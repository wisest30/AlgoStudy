class Solution {
public:
    int countPairs(vector<int>& A) {
        constexpr int MOD = 1e9 + 7;
        unordered_map<int, int> M;
        
        int ret = 0;
        for(auto a : A) {
            for(auto i = 0; i <= 21; ++i)
                if(M.count((1 << i) - a))
                    ret = (ret + M[(1 << i) - a]) % MOD;
            
            M[a]++;
        }
        
        return ret;
    }
};
