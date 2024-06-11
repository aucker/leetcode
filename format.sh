#!/bin/sh

PROJECT_DIR="./daily"

find $PROJECT_DIR -name uthash -prune -o -name "*.cpp" -o -name "*.c" -o -name "*.h" | xargs clang-format -i

git add --all
