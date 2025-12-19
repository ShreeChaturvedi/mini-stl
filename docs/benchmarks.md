# Benchmarks

This report summarizes microbenchmarks that compare my-stl containers to their closest `std::` equivalents.
Each benchmark runs the same operation with the same input size and prints timing samples.

## Methodology

- Build type: `Release` (`-O3` for `stl_bench`)
- Warmup iterations: 1
- Sample iterations: 5
- Input size (`n`): 200000
- Reported metric: median nanoseconds per operation

## How to Reproduce

```bash
python3 scripts/bench/run.py --n 200000 --iters 5 --warmup 1
python3 scripts/bench/report.py --run docs/benchmarks/runs/bench-YYYYMMDD-HHMMSS.json
```

## Latest Run

See `docs/benchmarks/runs/` for raw outputs and `docs/benchmarks/bench_summary.csv` for a table view.
The chart below shows the ratio (my-stl / std). Lower is better.

![Benchmark ratio chart](benchmarks/charts/ratio.svg)

## Notes

- Microbenchmarks measure specific operations and can be sensitive to allocator, CPU scaling, and compiler flags.
- Use the scripts above to regenerate results on your hardware for accurate comparisons.
