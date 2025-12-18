#include "bench.hpp"

#include "flat-set/flat_set.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <numeric>
#include <random>
#include <set>
#include <vector>

namespace {

std::vector<int> shuffled_keys(std::size_t n) {
  std::vector<int> keys(n);
  std::iota(keys.begin(), keys.end(), 0);
  std::mt19937 rng(12345);
  std::shuffle(keys.begin(), keys.end(), rng);
  return keys;
}

}  // namespace

BENCH_CASE("flat_set/build+find (mini-stl)") {
  const auto keys = shuffled_keys(n);

  stl_bench::run_samples("flat_set/build+find (mini-stl)", n, [&] {
    FlatSet<int> s;
    s.reserve(n);
    for (std::size_t i = 0; i < n; ++i) s.insert(keys[i]);

    std::int64_t sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
      auto it = s.find(keys[i]);
      if (it != s.end()) sum += *it;
    }
    stl_bench::do_not_optimize(sum);
  });
}

BENCH_CASE("flat_set/build+find (std::set)") {
  const auto keys = shuffled_keys(n);

  stl_bench::run_samples("flat_set/build+find (std::set)", n, [&] {
    std::set<int> s;
    for (std::size_t i = 0; i < n; ++i) s.insert(keys[i]);

    std::int64_t sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
      auto it = s.find(keys[i]);
      if (it != s.end()) sum += *it;
    }
    stl_bench::do_not_optimize(sum);
  });
}

