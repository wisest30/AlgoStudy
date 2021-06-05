class Solution {
public:
    
    bool canReach(string s, int minJump, int maxJump) {
        auto ps = vector<int>{0, 1};
        for(auto i = 1; i < (int)s.size(); ++i) {
            int l = max(0, i - maxJump);
            int r = max(0, i - minJump + 1);
            if(s[i] == '0' && ps[r] - ps[l] > 0) ps.push_back(ps.back() + 1);
            else ps.push_back(ps.back());
        }
        
        return ps[(int)ps.size() - 1] - ps[(int)ps.size() - 2];
    }
};
