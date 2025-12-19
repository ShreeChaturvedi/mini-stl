# RingBuffer<T, N>

A fixed-capacity circular buffer backed by `std::array`.

## Highlights

- O(1) push/pop/peek with wrap-around indices.
- Capacity is a compile-time constant (`N > 0`).

## API Notes

- `push` throws if the buffer is full.
- `pop` and `peek` throw if the buffer is empty.
- `size`, `empty`, and `full` are O(1).

## Complexity

- `push`, `pop`, `peek`: O(1)
- `size`, `empty`, `full`: O(1)

## Differences vs `std::` containers

- Fixed capacity; no dynamic growth.
- Minimal API (no iterators).

## Example

```cpp
#include "ring-buffer/ring_buffer.hpp"

RingBuffer<int, 4> rb;
rb.push(1);
int front = rb.peek();
rb.pop();
```
