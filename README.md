# my-stl

[![ci](https://github.com/ShreeChaturvedi/my-stl/actions/workflows/ci.yml/badge.svg)](https://github.com/ShreeChaturvedi/my-stl/actions/workflows/ci.yml)
[![license](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![c++](https://img.shields.io/badge/C%2B%2B-23-blue.svg)](https://isocpp.org/)

A modern C++23 "build-your-own STL" project: header-only containers, RAII utilities, tests, and published benchmarks.

## Highlights

- Header-only containers with STL-like APIs and deterministic behavior.
- Self-hosting where it makes sense (containers built on other my-stl containers).
- Full unit test suite and reproducible benchmarks with published results.

## Containers

Sequence:
`ArrayList`, `Vector`, `Deque`, `ForwardList`, `LinkedList`, `List`, `RingBuffer`, `SmallVector`, `StableVector`,
`Span`, `basic_string`.

Associative:
`map`/`multimap`, `set`/`multiset`, `FlatMap`, `FlatSet`.

Unordered:
`unordered_map`, `unordered_set`, `unordered_multimap`, `unordered_multiset`.

Adaptors:
`Stack`, `Queue`, `PriorityQueue`, `Heap`.

Utilities:
`LRUCache`, `Trie`, `unique_ptr` (plus internal `RbTree`).

## Design Notes

- Header-only: everything is `*.hpp` + `*.tpp`, included via CMake include paths.
- Self-hosting where it fits:
  - `Heap` uses `Vector`
  - `unordered_map` uses `Vector` + `ForwardList`
  - `LRUCache` uses `List` + `unordered_map`
  - `Stack` uses `Vector`, `Queue` uses `List`, `PriorityQueue` uses `Heap`
- APIs are STL-like with deliberate simplifications documented in `docs/containers/`.

## Build and Test

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
./build/stl_tests
```

## Benchmarks (Latest Run)

Run file: `docs/benchmarks/runs/bench-20251219-132313-m2.json`

- Apple M2, macOS 15.5
- Apple clang 17.0.0
- Release (`-O3`)

Median ns/op (ratio = my-stl / std):

| Case | my-stl | std | Ratio |
| --- | --- | --- | --- |
| Deque push_back+pop_front | 1.831 | 5.155 | 0.355 |
| Vector push_back (no reserve) | 1.184 | 0.985 | 1.202 |
| Vector push_back (reserve) | 0.470 | 0.467 | 1.007 |
| unordered_map emplace (reserve) | 48.570 | 41.019 | 1.184 |
| map build+find | 316.520 | 236.631 | 1.338 |
| set build+find | 246.726 | 190.280 | 1.297 |
| flat_map build+find | 8675.880 | 204.992 | 42.323 |
| flat_set build+find | 4858.020 | 201.612 | 24.096 |
| small_vector push_back | 1.206 | 0.810 | 1.488 |
| stable_vector push_back | 16.427 | 14.426 | 1.139 |

Full results: `docs/benchmarks/bench_summary.csv`

![Benchmark ratio chart](docs/benchmarks/charts/ratio.svg)

## Run Benchmarks

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/stl_bench --list
./build/stl_bench --n 200000 --iters 5 --warmup 1 --filter vector
```

Detailed methodology and scripts: `docs/benchmarks.md` and `scripts/bench/`.

## Documentation

- `docs/containers/README.md` -- per-container notes, complexity, differences vs `std::`
- `docs/benchmarks.md` -- benchmark methodology and results

## Contributing

See `CONTRIBUTING.md`.

## License

MIT -- see `LICENSE`.
