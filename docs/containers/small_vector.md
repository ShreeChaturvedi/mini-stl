# SmallVector<T, InlineCapacity>

A vector with inline storage to avoid heap allocations for small sizes.

## Highlights

- Inline buffer for up to `InlineCapacity` elements.
- `using_inline_storage()` reports whether the inline buffer is active.

## API Notes

- STL-like `push_back`, `emplace_back`, `insert`, `erase`.
- `swap` is supported and handles inline/external storage.

## Complexity

- `push_back`: amortized O(1)
- `insert`, `erase`: O(n)

## Differences vs `std::vector`

- Inline storage for small sizes.
- No allocator template parameter.

## Example

```cpp
#include "small-vector/small_vector.hpp"

SmallVector<int, 8> v;
v.push_back(1);
v.push_back(2);
```
