#! /bin/bash
set -e
#git checkout lag-adjusted-curvature-velocity
#git pull --rebase origin master

git checkout pfeifer-always-on-lateral
git push --force

git checkout pfeifer-current-max-speed
git push --force

git checkout pfeifer-experimental-mode-toggle
git push --force

git checkout pfeifer-fast-boot
git push --force

git checkout pfeifer-gap-adjust-control
git push --force

git checkout pfeifer-hkg-long-control-tune
git push --force

git checkout pfeifer-lane-detection
git push --force

git checkout pfeifer-nudgeless-lane-change
git push --force

git checkout pfeifer-speed-limit-control
git push --force

git checkout pfeifer-vtsc
git push --force

git checkout pfeifer-mapd
git push --force

git checkout pfeifer-button-manager
git push --force

git checkout pfeifer-gap-adjust-button
git push --force
