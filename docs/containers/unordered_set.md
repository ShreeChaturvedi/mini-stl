# unordered_set<K>

A hash set implemented on top of `unordered_map<K, unit>`.

## Highlights

- Average O(1) lookup/insert/erase.
- Thin adapter around `unordered_map`.

## API Notes

- `insert` returns `{iterator, bool}` indicating whether insertion happened.
- `erase(key)` returns `true` if a key was removed.
- `reserve(n)` forwards to the underlying map.

## Complexity

- Expected O(1) `find`, `insert`, `erase`
- Worst-case O(n)

## Differences vs `std::unordered_set`

- Minimal API (no bucket interface or load-factor controls).
- No allocator template parameter.

## Example

```cpp
#include "unordered-set/unordered_set.hpp"

unordered_set<int> s;
s.insert(1);
s.erase(1);
```
