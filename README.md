# mini-stl

A modern C++ (C++23) “build-your-own-STL” project: hand-rolled containers, RAII utilities, tests, and benchmarks.

## Containers

- `array-list` — `ArrayList<T>`
- `linked-list` — `LinkedList<T>`
- `ring-buffer` — `RingBuffer<T, capacity>`
- `heap` — `Heap<T, compare, branches>`
- `vector` — `Vector<T>`
- `unordered-map` — `unordered_map<K, V>`
- `unique-ptr` — `unique_ptr<T>`
- `trie` — `Trie`
- `lru-cache` — `LRUCache<K, V>`

## Roadmap

STL containers not implemented yet:

- Sequence: `deque`, `list` (doubly-linked), `forward_list`, `span`, `basic_string`
- Associative: `map`, `set`, `multimap`, `multiset`
- Unordered: `unordered_set`, `unordered_multimap`, `unordered_multiset`
- Adapters: `stack`, `queue`, `priority_queue`

Common “Boost-style” containers worth adding:

- `small_vector` (inline storage), `flat_map`/`flat_set` (sorted vector-backed), `stable_vector`
- `circular_buffer` (already covered by `RingBuffer<T, N>`, modulo API differences)

## Build + Test

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
./build/stl_tests
```

## Benchmarks

```bash
./build/stl_bench --list
./build/stl_bench --n 200000 --filter vector
```

Benchmarks are microbenchmarks: each case runs the same operation over the same input size for the custom container and
the closest `std::` container, then prints total time and time/op. Use `--n` to control the operation count and
`--filter` to run a subset.

## Coverage (Clang)

```bash
cmake -S . -B build-cov -DCMAKE_BUILD_TYPE=Debug -DSTL_ENABLE_COVERAGE=ON
cmake --build build-cov -j
LLVM_PROFILE_FILE=build-cov/coverage.profraw ./build-cov/stl_tests
llvm-profdata merge -sparse build-cov/coverage.profraw -o build-cov/coverage.profdata
llvm-cov report ./build-cov/stl_tests -instr-profile=build-cov/coverage.profdata
```
