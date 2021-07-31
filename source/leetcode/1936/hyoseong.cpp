class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ret = 0, n = rungs.size();
        for(auto i = 0; i < n; ++i) {
            auto cur = i == 0 ? 0 : rungs[i - 1];
            auto nxt = rungs[i];
            
            ret += (nxt - cur + dist - 1) / dist - 1;
        }
        
        return ret;
    }
};
