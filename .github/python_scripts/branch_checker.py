"""
Branch name validator
"""
import argparse
import re


def validate_branch_name(branch_name: str, regex: str):
    """
    Validates the branch name against a regex pattern.

    Parameters
    ----------
    branch_name : str
        The name of the branch to validate.
    regex : str
        The regex pattern to match the branch name against.

    Raises
    ------
    ValueError
        If the branch name does not match the required pattern.
    """
    compiled_regex = re.compile(regex)
    if compiled_regex.match(branch_name):
        print(f"Branch name {branch_name} does follow the required pattern.")
    else:
        raise ValueError(f"Branch name {branch_name} does NOT follow the required pattern")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Validate a branch name against a given regex pattern.")
    parser.add_argument("-n", "--branch-name", help="The name of the branch to be validated.", required=True, type=str)
    parser.add_argument("-r", "--branch-regex", help="The regex pattern to validate the branch name against.",
                        required=True, type=str)
    args = vars(parser.parse_args())

    validate_branch_name(args["branch_name"], args["branch_regex"])
