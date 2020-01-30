#!/bin/bash

git pull --no-edit
git fetch upstream
git checkout master
git merge upstream/master -m "automerging"
