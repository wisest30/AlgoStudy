class Solution {
public:
  Solution() : trans(128, 0) {
    for (int i = 'a'; i <= 'z'; ++i) {
      trans[i] = (i - 'a' + 1) % 10 + (i - 'a' + 1) / 10;
    }
  }

  int getLucky(string s, int k) {
    int ret = 0;
    for (const auto c : s) ret += trans[c];

    while (--k) {
      int prev = ret;
      ret = 0;
      while (prev) {
        ret += prev % 10;
        prev /= 10;
      }
    }
    return ret;
  }
private:
  vector<int> trans;
};
