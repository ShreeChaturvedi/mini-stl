template <typename Key, typename Compare>
typename FlatSet<Key, Compare>::iterator FlatSet<Key, Compare>::lower_bound(
    const Key& key) noexcept {
  return std::lower_bound(data_.begin(), data_.end(), key, [this](const Key& a, const Key& b) {
    return comp_(a, b);
  });
}

template <typename Key, typename Compare>
typename FlatSet<Key, Compare>::const_iterator FlatSet<Key, Compare>::lower_bound(
    const Key& key) const noexcept {
  return std::lower_bound(data_.begin(), data_.end(), key, [this](const Key& a, const Key& b) {
    return comp_(a, b);
  });
}

template <typename Key, typename Compare>
std::pair<typename FlatSet<Key, Compare>::iterator, bool> FlatSet<Key, Compare>::insert(
    const Key& key) {
  auto it = lower_bound(key);
  if (it != end() && keys_equal(comp_, *it, key)) return {it, false};
  it = data_.insert(it, key);
  return {it, true};
}

template <typename Key, typename Compare>
std::pair<typename FlatSet<Key, Compare>::iterator, bool> FlatSet<Key, Compare>::insert(Key&& key) {
  auto it = lower_bound(key);
  if (it != end() && keys_equal(comp_, *it, key)) return {it, false};
  it = data_.insert(it, std::move(key));
  return {it, true};
}

template <typename Key, typename Compare>
typename FlatSet<Key, Compare>::iterator FlatSet<Key, Compare>::find(const Key& key) noexcept {
  auto it = lower_bound(key);
  if (it != end() && keys_equal(comp_, *it, key)) return it;
  return end();
}

template <typename Key, typename Compare>
typename FlatSet<Key, Compare>::const_iterator FlatSet<Key, Compare>::find(
    const Key& key) const noexcept {
  auto it = lower_bound(key);
  if (it != end() && keys_equal(comp_, *it, key)) return it;
  return end();
}

template <typename Key, typename Compare>
typename FlatSet<Key, Compare>::size_type FlatSet<Key, Compare>::erase(const Key& key) {
  auto it = find(key);
  if (it == end()) return 0;
  data_.erase(it);
  return 1;
}

