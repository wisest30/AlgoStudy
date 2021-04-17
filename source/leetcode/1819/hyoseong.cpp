class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        constexpr int MAX_N = 200000 + 1;
        
        vector<bool> mark(MAX_N);
        for(auto x : nums)
            mark[x] = true;
        
        int ret = 0;
        for(auto i = 1; i <= MAX_N; ++i) {
            int g = -1;
            for(auto j = i; j <= MAX_N; j += i) {
                if(!mark[j]) continue;
                if(g == -1) g = j;
                else g = __gcd(g, j);
            }
            
            if(g == i)
                ret++;
        }
        
        return ret;
    }
};
