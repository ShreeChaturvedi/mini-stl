#include "test.hpp"

#include "trie/trie.hpp"

TEST_CASE("Trie: insert/contains/erase") {
  Trie t;
  CHECK(!t.contains("cat"));
  t.insert("cat");
  t.insert("car");
  CHECK(t.contains("cat"));
  CHECK(t.contains("car"));
  CHECK(!t.contains("cap"));
  CHECK(!t.contains("ca"));

  t.erase("does-not-exist");
  t.erase("cat");
  CHECK(!t.contains("cat"));
  CHECK(t.contains("car"));
}
