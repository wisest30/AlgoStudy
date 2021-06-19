#define ull unsigned long long
#define uint unsigned int

class Solution {
public:
  int minFlips(string s) {
    if ((s.size() & 0x01) == 0) {
      int ans[2] = { 0, 0 };

      for (int i = 0; i < s.size(); ++i) {
        ans[0] += (i & 0x01) == (s[i] - '0');
        ans[1] += (i & 0x01) != (s[i] - '0');
      }

      return min(ans[0], ans[1]);
    }

    vector<vector<int>> cnt(2, vector<int>(s.size() + 1));

    cnt[0][0] += 0; // 1010...
    cnt[1][0] += 0; // 0101...
    for (int i = 1; i <= s.size(); ++i) {
      cnt[0][i] += cnt[0][i - 1] + ((i & 0x01) == (s[i - 1] - '0'));
      cnt[1][i] += cnt[1][i - 1] + ((i & 0x01) != (s[i - 1] - '0'));
    }

    int ans = 1000000;

    for (int i = 0; i < s.size(); ++i) {
      ans = min(ans, cnt[0][s.size()] - cnt[0][i] + cnt[1][i] - cnt[1][0]);
      ans = min(ans, cnt[1][s.size()] - cnt[1][i] + cnt[0][i] - cnt[0][0]);
    }

    return ans;
  }
};
