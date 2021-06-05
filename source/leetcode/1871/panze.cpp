class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    set<int> visit;
    visit.insert(0);

    for (int i = 1; i < n; ++i) {
      if (s[i] == '0') {
        const auto &ub = visit.lower_bound(i - maxJump);
          
        if (ub == visit.end() || *ub < i - maxJump || *ub > i - minJump) {
          continue;
        }
        visit.insert(i);
      }
    }

    return visit.find(s.size() - 1) != visit.end();
  }
};