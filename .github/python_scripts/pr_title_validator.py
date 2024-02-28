"""
PR title validator
"""
import os
import re


def validate_pr_title_and_description(
        pr_title: str,
        pr_description: str,
        regex: str,
) -> str:
    """
    Validates the Pull Request title and description against a regex pattern

    Parameters
    ----------
    pr_title : str
        The title of the Pull Request
    pr_description : str
        The description of the Pull Request
    regex : str
        The regex pattern to use for validation

    Returns
    -------
    str
        The type of the Pull Request
    """
    compiled_regex = re.compile(regex)
    match = compiled_regex.search(pr_title)

    # (feat|feature|fix|ci|docs|chore)(\(CT-[0-9]+\))?(!)?:\s((\w+\s*)+)
    # Python 3.10 does not support named groups in regex, so we use numbered groups instead
    if match:
        pr_type = match.group(1)
        pr_scope = match.group(2)
        pr_breaking_change = match.group(3)
        pr_summary = match.group(4)

        # We need to ensure that all components in the pull request title exist
        if any(element is None for element in [pr_summary, pr_scope, pr_type]):
            raise ValueError(f"One of the components in the Pull Request title is missing or invalid, "
                             f"please follow the following pattern: {regex}")

        # We need to ensure that a breaking change is indicated by both the PR title and PR Description
        if (pr_breaking_change and pr_description.startswith("BREAKING CHANGE")) or (
                not pr_breaking_change and not pr_description.startswith("BREAKING CHANGE")):
            if pr_breaking_change:
                pr_type = "breaking_change"
            print(f"Pull Request title is valid\n"
                  f"Pull Request title: {pr_title}\n"
                  f"Type: {pr_type}\nScope: {pr_scope}\n"
                  f"Breaking change: {pr_breaking_change}\n"
                  f"Summary: {pr_summary}")
            return pr_type

        raise ValueError("A breaking change MUST be indicated by BOTH the Pull Request title '!' "
                         "and the Pull Request description with 'BREAKING CHANGE' at the start")

    raise ValueError(f"Invalid Pull Request title please follow the following pattern: {regex}")


if __name__ == "__main__":
    validate_pr_title_and_description(
        pr_title=os.environ["PR_TITLE"],
        pr_description=os.environ["PR_DESCRIPTION"],
        regex=os.environ["PR_TITLE_REGEX"]
    )
