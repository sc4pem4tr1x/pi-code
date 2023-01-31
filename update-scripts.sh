#!/bin/sh

git fetch origin
git add .
git commit -m "commit before merge"

git merge
