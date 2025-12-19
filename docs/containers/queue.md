# Queue<T>

A FIFO adapter over an underlying container (default: `List<T>`).

## Highlights

- O(1) push/pop when using `List<T>`.
- Minimal STL-like API: `front`, `back`, `push`, `emplace`, `pop`.

## API Notes

- Default underlying container is `List<T>`.
- `pop` removes from the front; `push` adds to the back.

## Complexity

- `push`, `pop`, `front`, `back`: O(1)

## Differences vs `std::queue`

- No `swap`.
- No access to the underlying container.

## Example

```cpp
#include "queue/queue.hpp"

Queue<int> q;
q.push(1);
q.emplace(2);
q.pop();
```
