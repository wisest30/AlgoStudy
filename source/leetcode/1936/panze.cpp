class Solution {
public:
  int addRungs(vector<int>& rungs, int dist) {
    int ret = 0;
    int prev = 0;
    for (auto h : rungs) {
      ret += (h - prev - 1) / dist;
      prev = h;
    }
    return ret;
  }
};