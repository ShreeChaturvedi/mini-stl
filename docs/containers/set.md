# set<K> and multiset<K>

Ordered set containers built on a red-black tree.

## Highlights

- `set` enforces uniqueness; `multiset` allows duplicates.
- Ordered iteration by key.
- `lower_bound`, `upper_bound`, `equal_range` provided.

## API Notes

- `insert` returns `pair<iterator,bool>` for `set`.
- `multiset` provides `erase_one` and `erase_all`.

## Complexity

- `find`, `insert`, `erase`, `lower_bound`, `upper_bound`: O(log n)

## Differences vs `std::set` / `std::multiset`

- No allocator template parameter.
- Minimal API (no hint insert, no node handles).

## Example

```cpp
#include "set/set.hpp"

set<int> s;
s.insert(1);
s.insert(2);
```
