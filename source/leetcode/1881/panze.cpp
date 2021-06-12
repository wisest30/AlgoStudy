class Solution {
public:
  string maxValue(string n, int x) {
    if (n[0] == '-') {
      for (size_t i = 1; i < n.size(); ++i) {
        if (n[i] - '0' > x) {
          n.insert(i, 1, (char)(x + '0'));
          break;
        } else if (i == n.size() - 1) {
          n.push_back((char)(x + '0'));
          break;
        }
      }
    } else {
      for (size_t i = 0; i < n.size(); ++i) {
        if (n[i] - '0' < x) {
          n.insert(i, 1, (char)(x + '0'));
          break;
        } else if (i == n.size() - 1) {
          n.push_back((char)(x + '0'));
          break;
        }
      }
    }

    return n;
  }
};