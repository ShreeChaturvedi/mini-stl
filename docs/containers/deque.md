# Deque<T>

A dynamically growing circular buffer with random-access iterators.

## Highlights

- `push_front` / `push_back` / `pop_front` / `pop_back` in O(1) amortized time.
- Random-access iterators backed by index math.
- Storage is a single contiguous buffer (not segmented like `std::deque`).

## API Notes

- `operator[]` is unchecked; `at` throws on out-of-range.
- `front` / `back` throw on empty.
- `clear` resets size and head index.

## Complexity

- `push_front`, `push_back`, `pop_front`, `pop_back`: amortized O(1)
- `operator[]`, `at`: O(1)

## Differences vs `std::deque`

- Uses a single contiguous buffer instead of block segments.
- Reallocation invalidates all iterators and references.
- No allocator template parameter.

## Example

```cpp
#include "deque/deque.hpp"

Deque<int> d;
d.push_back(1);
d.push_front(0);
d.pop_back();
```
