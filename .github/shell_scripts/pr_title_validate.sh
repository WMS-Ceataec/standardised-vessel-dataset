python $PYTHON_SCRIPTS_PATH/pr_title_validator.py || exit 3
short_sha=$(git rev-parse --short HEAD)
last_tag=$(git describe --tags --abbrev=0 --match "v[0-9]*.[0-9]*.[0-9]*")
commit_count_since_last_tag=$(git rev-list $last_tag..HEAD --count)

# Creating Tags for Pull Request deployments
export VersionLabelTag=$last_tag
export VersionLabelRevision=$last_tag.$commit_count_since_last_tag
export VersionLabelInformational=$last_tag+$commit_count_since_last_tag.Branch.$1.Sha.$short_sha

# Printing Tags
echo "VersionLabelTag: $VersionLabelTag"
echo "VersionLabelRevision: $VersionLabelRevision"
echo "VersionLabelInformational: $VersionLabelInformational"

# Make variables available for next steps
echo "VersionLabelTag=$VersionLabelTag" >> "$GITHUB_ENV"
echo "VersionLabelRevision=$VersionLabelRevision" >> "$GITHUB_ENV"
echo "VersionLabelInformational=$VersionLabelInformational" >> "$GITHUB_ENV"