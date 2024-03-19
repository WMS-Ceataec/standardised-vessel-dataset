"""
Version number generator for tag creation
"""
import argparse
import os
import re


def generate_new_semver_version_number(current_version_tag: str, pr_type: str, tag_prefix: str) -> str:
    """
    Generates a new SemVer version number based on the current version tag and the type of change

    Parameters
    ----------
    current_version_tag : str
        The current version tag
    pr_type : str
        The type of change
    tag_prefix : str
        Tag Prefix

    Returns
    -------
    str
        The new SemVer version number
    """
    current_version_tag_list = current_version_tag.replace(tag_prefix, "").split(".")
    major = int(current_version_tag_list[0])
    minor = int(current_version_tag_list[1])
    patch = int(current_version_tag_list[2])
    print(f"PR Type {pr_type}")

    match pr_type:
        case "feat" | "feature":
            print(f"Change type is {pr_type}, bumping Minor version number")
            minor += 1
            patch = 0
        case "fix" | "bugfix" | "style" | "refactor" | "perf" | "test":
            print(f"Change type is {pr_type}, bumping Patch version number")
            patch += 1
        case "ci" | "docs" | "chore":
            print(f"Change type is {pr_type}, no version number increase needed")
        case "breaking_change":
            print("Change type is BREAKING CHANGE, bumping Major version number")
            major += 1
            minor = 0
            patch = 0
        case _:
            print("Change type is invalid")
            raise ValueError("Change type is invalid, check that your Pull Request title is in the correct format")
    return f"{tag_prefix}{major}.{minor}.{patch}"


def get_pr_type(pr_title_regex: str, pr_title: str) -> str:
    """
    Get PR type

    Parameters
    ----------
    pr_title_regex : str
        The regex pattern to use for validation
    pr_title : str
        The title of the Pull Request

    Returns
    -------
    str
        The type of the Pull Request
    """
    compiled_regex = re.compile(pr_title_regex)
    match = compiled_regex.search(pr_title)

    if match:
        pr_type = match.group(1)
        pr_breaking_change = match.group(3)
        if not pr_type:
            raise ValueError(f"One of the components in the Pull Request title is missing or invalid, "
                             f"please follow the following pattern: {pr_title_regex}")
        if pr_breaking_change:
            pr_type = "breaking_change"
        return pr_type

    raise ValueError(f"Invalid merged commit pattern please follow the following pattern: {pr_title_regex}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Description of your program')
    parser.add_argument('-t', '--pr-title', help='Pull Request title', required=True)
    parser.add_argument('-c', '--current-version', help='Current version tag', required=True)
    parser.add_argument('-p', '--tag-prefix', help='Tag Prefix', required=True)
    args = vars(parser.parse_args())

    input_pr_type = get_pr_type(os.environ['PR_TITLE_REGEX'], args['pr_title'])
    new_version_tag = generate_new_semver_version_number(args['current_version'], input_pr_type, args['tag_prefix'])

    with open("new_version_file", "w", encoding="utf-8") as new_version_file:
        new_version_file.write(new_version_tag)