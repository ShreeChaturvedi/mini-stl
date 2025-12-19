# map<K, V> and multimap<K, V>

Ordered associative containers built on a red-black tree.

## Highlights

- `map` enforces unique keys; `multimap` allows duplicates.
- Ordered iteration by key.
- `lower_bound`, `upper_bound`, `equal_range` provided.

## API Notes

- `map::operator[]` inserts a default-constructed value when missing.
- `multimap` exposes `erase_one` and `erase_all`.
- `insert` / `emplace` return `iterator` (or pair for `map`).

## Complexity

- `find`, `insert`, `erase`, `lower_bound`, `upper_bound`: O(log n)

## Differences vs `std::map` / `std::multimap`

- No allocator template parameter.
- Minimal API (no hint insert, no node handles).
- `map::erase` by key does nothing if missing (no return count).

## Example

```cpp
#include "map/map.hpp"

map<std::string, int> m;
m.emplace("a", 1);
m["b"] = 2;
auto it = m.find("a");
```
