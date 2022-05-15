class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ret = 0;
        for(auto i = 0; i < 30; ++i) {
            int cnt = 0;
            for(auto c : candidates)
                if(c & (1 << i))
                    ++cnt;
            
            ret = max(ret, cnt);
        }
        
        return ret;
    }
};
