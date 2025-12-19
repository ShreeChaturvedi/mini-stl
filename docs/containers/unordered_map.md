# unordered_map<K, V>

Hash table with separate chaining (`Vector<ForwardList<...>>` buckets).

## Highlights

- Average O(1) lookup/insert/erase.
- `reserve`, `rehash`, and `max_load_factor` control growth.

## API Notes

- `insert` / `emplace` overwrite existing values.
- `operator[]` inserts a default-constructed `V` if missing.
- `erase(key)` removes matching key (no return count).

## Complexity

- Expected O(1) `find`, `insert`, `erase`
- Worst-case O(n) with heavy collisions

## Differences vs `std::unordered_map`

- No allocator template parameter.
- Minimal API (no bucket interface, no `equal_range`).
- `insert` does not return an iterator/bool pair.

## Example

```cpp
#include "unordered-map/unordered_map.hpp"

unordered_map<std::string, int> m;
m.emplace("a", 1);
m["b"] = 2;
```
