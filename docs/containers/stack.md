# Stack<T>

A LIFO adapter over an underlying container (default: `Vector<T>`).

## Highlights

- Simple `push` / `pop` / `top` API.
- `emplace` forwards to the underlying container.

## API Notes

- Default container is `Vector<T>`.
- `pop` removes the top element.

## Complexity

- `push`, `pop`, `top`: amortized O(1)

## Differences vs `std::stack`

- No `swap`.
- No access to the underlying container.

## Example

```cpp
#include "stack/stack.hpp"

Stack<int> s;
s.push(1);
s.emplace(2);
s.pop();
```
