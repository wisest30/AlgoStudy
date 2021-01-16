class Solution {
public:
    int waysToSplit(vector<int>& A) {
        constexpr int MOD = 1e9 + 7;
        
        int n = A.size();
        vector<int> ps(n+1);
        for(auto i = 0; i < n; ++i) ps[i+1] = ps[i] + A[i];
        
        int ret = 0;
        for(auto i = 2; i < n; ++i) {
            int su = ps[n] - ps[i];
            if(ps[i] > su * 2) break;
            
            int min_idx = lower_bound(ps.begin(), ps.begin() + i, ps[i] - su) - ps.begin();
            if(min_idx == 0) min_idx++;
            if(min_idx == i) continue;
            
            int max_idx = upper_bound(ps.begin(), ps.begin() + i, ps[i] / 2) - ps.begin() - 1;
            if(max_idx == i) max_idx--;
            if(max_idx < min_idx) continue;
            
            ret = (ret + max_idx - min_idx + 1) % MOD;
        }
        
        return ret;
    }
};
