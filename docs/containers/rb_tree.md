# RbTree<Value, KeyOfValue, Compare, Multi>

Internal red-black tree used by `map`/`set` and their multi variants.

## Highlights

- Balanced tree with O(log n) lookup/insert/erase.
- `Multi` parameter controls duplicate handling.

## API Notes

- Exposes iterators for in-order traversal.
- Supports `find`, `lower_bound`, `upper_bound`, and `erase`.

## Complexity

- `find`, `insert`, `erase`: O(log n)

## Notes

- This is an internal building block, not intended as a public-facing container.
