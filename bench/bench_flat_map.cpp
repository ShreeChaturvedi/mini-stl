#include "bench.hpp"

#include "flat-map/flat_map.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <map>
#include <numeric>
#include <random>
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

BENCH_CASE("flat_map/build+find (mini-stl)") {
  const auto keys = shuffled_keys(n);

  stl_bench::run_samples("flat_map/build+find (mini-stl)", n, [&] {
    FlatMap<int, int> m;
    m.reserve(n);
    for (std::size_t i = 0; i < n; ++i) m.insert({keys[i], static_cast<int>(i)});

    std::int64_t sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
      auto it = m.find(keys[i]);
      if (it != m.end()) sum += it->second;
    }
    stl_bench::do_not_optimize(sum);
  });
}

BENCH_CASE("flat_map/build+find (std::map)") {
  const auto keys = shuffled_keys(n);

  stl_bench::run_samples("flat_map/build+find (std::map)", n, [&] {
    std::map<int, int> m;
    for (std::size_t i = 0; i < n; ++i) m.emplace(keys[i], static_cast<int>(i));

    std::int64_t sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
      auto it = m.find(keys[i]);
      if (it != m.end()) sum += it->second;
    }
    stl_bench::do_not_optimize(sum);
  });
}
