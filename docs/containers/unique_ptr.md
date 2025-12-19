# unique_ptr<T>

A single-owner smart pointer with move-only semantics.

## Highlights

- RAII ownership with deterministic destruction.
- `release`, `reset`, `get`, and `operator*`/`operator->`.

## API Notes

- Uses `std::default_delete<T>` internally.
- Copy operations are deleted; move operations transfer ownership.

## Differences vs `std::unique_ptr`

- No custom deleter template parameter.
- No array specialization (`unique_ptr<T[]>`).

## Example

```cpp
#include "unique-ptr/unique_ptr.hpp"

unique_ptr<int> p(new int(42));
p.reset(new int(7));
```
