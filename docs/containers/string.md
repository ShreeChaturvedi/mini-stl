# basic_string<CharT>

A small-string-optimized (SSO) string with a minimal STL-like API.

## Highlights

- Inline buffer for small strings (SSO).
- `append`, `operator+=`, `push_back`.

## API Notes

- `view()` returns a `std::basic_string_view`.
- `reserve` grows capacity and keeps a null terminator.
- `at`, `front`, `back` throw on invalid access.

## Complexity

- `push_back`, `append`: amortized O(1)
- `operator[]`: O(1)

## Differences vs `std::basic_string`

- Minimal API (no `find`, `substr`, or allocator support).
- SSO capacity is fixed by the internal layout.

## Example

```cpp
#include "string/string.hpp"

basic_string<char> s("hi");
s.push_back('!');
```
