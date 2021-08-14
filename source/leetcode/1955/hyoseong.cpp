class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int n;
    vector<vector<long long>> dp;
    vector<int> A;
    
    long long recur(int idx, int status) {
        if(status == 3)
            return 1;
        else if(idx == n)
            return 0;
        
        auto& ret = dp[idx][status];
        if(ret != -1)
            return ret;
        
        if(A[idx] == status) {
            ret = recur(idx + 1, status) * 2 % MOD;
            ret = (ret + recur(idx + 1, status + 1)) % MOD;
        }
        else {
            ret = recur(idx + 1, status);
        }
        
        return ret;
    }
    
    int countSpecialSubsequences(vector<int>& nums) {
        n = nums.size();
        dp = vector<vector<long long>>(n, vector<long long>(3, -1));
        A = nums;
        
        auto ret = recur(0, 0);
        return ret;
    }
};
