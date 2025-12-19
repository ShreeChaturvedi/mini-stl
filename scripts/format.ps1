$clang = Get-Command clang-format -ErrorAction SilentlyContinue
if (-not $clang) {
  Write-Error "clang-format not found on PATH."
  exit 1
}

rg --files -g '*.hpp' -g '*.h' -g '*.tpp' -g '*.cpp' | ForEach-Object {
  & $clang.Path -i $_
}
