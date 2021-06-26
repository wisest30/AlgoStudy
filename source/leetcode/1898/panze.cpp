#define ull unsigned long long
#define uint unsigned int

class Solution {
  bool check(const string& s, const string& p) {
    int cnt = 0;

    for (const auto c : s) {
      if (c == p[cnt]) cnt++;
      if (cnt == p.size()) break;
    }

    return cnt == p.size();
  }

public:
  int maximumRemovals(string s, string p, vector<int>& removable) {
    int left = 0;
    int right = removable.size();
    while (left < right) {
      int mid = (left + right) / 2;

      vector<bool> removed(s.size(), 0);
      for (int i = 0; i <= mid; ++i) {
        removed[removable[i]] = true;
      }
      
      string s1;
      for (int i = 0; i < s.size(); ++i) {
        if (removed[i] == false) s1.push_back(s[i]);
      }

      if (check(s1, p) == true) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return right;
  }
};
