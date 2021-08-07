class Solution {
public:
  string maximumNumber(string num, vector<int>& change) {
    string ret = num;
    bool changed = false;
    for (int i = 0; i < num.size(); ++i) {
      if (num[i] - '0' < change[num[i] - '0']) {
        ret[i] = change[num[i] - '0'] + '0';
        changed = true;
      } else if (num[i] - '0' == change[num[i] - '0']) {
        continue;
      } else if (changed) {
        break;
      }
    }
    return ret;
  }
};