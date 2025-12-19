#!/usr/bin/env bash
set -euo pipefail

if ! command -v clang-format >/dev/null 2>&1; then
  echo "clang-format not found on PATH." >&2
  exit 1
fi

rg --files -g '*.hpp' -g '*.h' -g '*.tpp' -g '*.cpp' --null \
  | xargs -0 clang-format -i
