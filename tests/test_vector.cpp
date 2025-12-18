#include "test.hpp"

#include "vector/vector.hpp"

#include <string>

TEST_CASE("Vector: push_back/size/index") {
  Vector<int> xs;
  CHECK(xs.empty());
  for (int i = 0; i < 100; ++i) xs.push_back(i);
  CHECK_EQ(xs.size(), 100u);
  CHECK_EQ(xs[0], 0);
  CHECK_EQ(xs[99], 99);
}

TEST_CASE("Vector: front/back/pop_back/resize") {
  Vector<int> xs;
  CHECK_THROWS(xs.front());
  CHECK_THROWS(xs.back());
  CHECK_THROWS(xs.pop_back());

  xs.push_back(1);
  xs.push_back(2);
  CHECK_EQ(xs.front(), 1);
  CHECK_EQ(xs.back(), 2);
  xs.pop_back();
  CHECK_EQ(xs.size(), 1u);
  CHECK_EQ(xs.back(), 1);

  xs.resize(5);
  CHECK_EQ(xs.size(), 5u);
  CHECK_EQ(xs.front(), 1);
}

TEST_CASE("Vector: copy/move") {
  Vector<std::string> xs{"a", "b", "c"};
  Vector<std::string> ys = xs;
  CHECK_EQ(ys.size(), 3u);
  CHECK_EQ(ys[1], "b");

  Vector<std::string> zs = std::move(xs);
  CHECK_EQ(zs.size(), 3u);
  CHECK_EQ(zs[2], "c");
}

TEST_CASE("Vector: at throws") { CHECK_THROWS((Vector<int>{1, 2, 3}.at(99))); }
