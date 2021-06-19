// WA solution 
// 40 / 42 test cases passed.

#define ull unsigned long long
#define uint unsigned int

constexpr ull kMod = 1e9 + 7;

class Solution {
public:
  int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
    sort(packages.begin(), packages.end());

    vector<ull> cnt(packages.size() + 1);
    cnt[0] = 0;
    for (int i = 1; i <= packages.size(); ++i) {
      cnt[i] = cnt[i - 1] + packages[i - 1];
    }

    ull ans = kMod;

    for (auto box : boxes) {
      sort(box.begin(), box.end());

      if (box.back() < packages.back()) continue;

      ull wasted = 0;
      uint prev = 0;
      for (const auto b : box) {
        const auto search = upper_bound(packages.begin(), packages.end(), b);
        uint now = search - packages.begin();
        if (now == 0) continue;
        const uint diff = now - prev;

        wasted = (wasted + diff * b - (cnt[now] - cnt[prev])) % kMod;
        
        prev = now;
      }

      ans = min(ans, wasted);
    }

    return ans == kMod ? -1 : ans;
  }
};