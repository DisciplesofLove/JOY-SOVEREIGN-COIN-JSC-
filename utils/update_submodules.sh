#!/bin/sh
set -e

git submodule sync --recursive
# Update included submodules. Use --depth=1 to limit data when supported.
git submodule update --init --recursive
