#include "test.hpp"

#include "../heap/heap.hpp"

#include <algorithm>
#include <random>
#include <vector>

TEST_CASE("Heap: push/top/pop maintains order") {
  Heap<int> h;
  h.push(3);
  h.push(1);
  h.push(2);
  CHECK_EQ(h.top(), 1);
  CHECK_EQ(h.pop(), 1);
  CHECK_EQ(h.pop(), 2);
  CHECK_EQ(h.pop(), 3);
  CHECK(h.empty());
  CHECK_THROWS(h.pop());
}

TEST_CASE("Heap: heap sort matches std::sort") {
  std::vector<int> xs;
  std::mt19937 rng(123);
  std::uniform_int_distribution<int> dist(-1000, 1000);
  for (int i = 0; i < 2000; ++i) xs.push_back(dist(rng));

  auto ys = xs;
  std::sort(ys.begin(), ys.end());

  Heap<int>::sort(xs);
  CHECK(xs == ys);
}

