#!/usr/bin/env bash

# Extract the current version tag and the commit sha
current_version_tag=$(git describe --tags --abbrev=0 --match "v[0-9]*.[0-9]*.[0-9]*")
current_version_tag_commit=$(git rev-list -n 1 $current_version_tag)
echo "Current version tag"
echo $current_version_tag
echo "Current version tag commit"
echo $current_version_tag_commit
# Extract the latest commit sha
latest_commit_id=$(git rev-parse HEAD)
if [ $current_version_tag_commit != $latest_commit_id ]; then
    echo "This is NOT a manual rerun"
    merged_commit_message_title=$(git log -1 --pretty=%s)
    merged_commit_message_content=$(git log -1 --pretty=%b)
    echo $merged_commit_message_content
    python $PYTHON_SCRIPTS_PATH/version_number_generator.py -t "$merged_commit_message_title" \
                                                            -c "$current_version_tag" || exit 3
    echo "New version is"
    new_version_tag=$(head -n 1 new_version_file)
    echo $new_version_tag

    if [[ $new_version_tag != $current_version_tag ]]; then
        git tag "$new_version_tag" || exit 3
        last_tag=$new_version_tag
        commit_count_since_last_tag=0
    else
        echo "Tag already exists, no new version required"
    fi
else
    echo "This is a manual rerun, no new version required"
    last_tag=$(git describe --tags --abbrev=0 --match "v[0-9]*.[0-9]*.[0-9]*")
    commit_count_since_last_tag=$(git rev-list $last_tag..HEAD --count)
fi

# Setting Variables
short_sha=$(git rev-parse --short HEAD)

# Creating Tags
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
