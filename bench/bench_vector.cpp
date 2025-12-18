#include "bench.hpp"

#include "vector/vector.hpp"

#include <random>
#include <vector>

BENCH_CASE("vector/push_back_no_reserve") {
  std::mt19937 rng(123);
  std::uniform_int_distribution<int> dist(0, 1'000'000);

  {
    Vector<int> xs;
    stl_bench::run_samples("Vector<int>::push_back (no reserve)", n, [&] {
      for (std::size_t i = 0; i < n; ++i) xs.push_back(dist(rng));
    });
    stl_bench::do_not_optimize(xs.size());
  }

  {
    std::vector<int> xs;
    stl_bench::run_samples("std::vector<int>::push_back (no reserve)", n, [&] {
      for (std::size_t i = 0; i < n; ++i) xs.push_back(dist(rng));
    });
    stl_bench::do_not_optimize(xs.size());
  }
}

BENCH_CASE("vector/push_back_reserve") {
  std::mt19937 rng(123);
  std::uniform_int_distribution<int> dist(0, 1'000'000);

  {
    Vector<int> xs;
    xs.reserve(n);
    stl_bench::run_samples("Vector<int>::push_back (reserve)", n, [&] {
      for (std::size_t i = 0; i < n; ++i) xs.push_back(dist(rng));
    });
    stl_bench::do_not_optimize(xs.size());
  }

  {
    std::vector<int> xs;
    xs.reserve(n);
    stl_bench::run_samples("std::vector<int>::push_back (reserve)", n, [&] {
      for (std::size_t i = 0; i < n; ++i) xs.push_back(dist(rng));
    });
    stl_bench::do_not_optimize(xs.size());
  }
}
