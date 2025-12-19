# ForwardList<T>

A singly linked list with a `before_begin()` sentinel to simplify insert/erase.

## Highlights

- O(1) `push_front`, `insert_after`, `erase_after`.
- Low overhead, forward-only iteration.

## API Notes

- `before_begin()` returns a sentinel iterator before the first element.
- `emplace_front` and `emplace_after` construct in place.
- `front` throws on empty.

## Complexity

- `push_front`, `insert_after`, `erase_after`: O(1)
- Traversal: O(n)

## Differences vs `std::forward_list`

- No allocator template parameter.
- Minimal API (no `splice_after`, no `remove_if`).

## Example

```cpp
#include "forward-list/forward_list.hpp"

ForwardList<int> list;
list.push_front(2);
list.push_front(1);
auto it = list.before_begin();
list.insert_after(it, 0);
```
