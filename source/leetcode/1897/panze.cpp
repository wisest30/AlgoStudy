class Solution {
public:
  bool makeEqual(vector<string>& words) {
    vector<int> cnt(26, 0);

    for (const auto& word : words) {
      for (const auto c : word) {
        ++cnt[c - 'a'];
      }
    }

    for (const auto count : cnt) {
      if (count % words.size() != 0) return false;
    }
    return true;
  }
};