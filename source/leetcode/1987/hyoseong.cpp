class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    string binary;
    vector<vector<int>> dp;
    
    int recur(int idx, int start) {
        if(idx == binary.size())
            return 0;
        
        auto& ret = dp[idx][start];
        if(ret != -1)
            return ret;
        
        if(binary[idx] - '0' == start) {
            ret = recur(idx + 1, start) + recur(idx + 1, start ^ 1) + 1;
            ret %= MOD;
        }
        else
            ret = recur(idx + 1, start);
        
        return ret;
    }
    
    int numberOfUniqueGoodSubsequences(string binary) {
        this->binary = binary;
        dp = vector<vector<int>>(binary.size(), vector<int>(2, -1));
        
        auto ret = recur(0, 1);
        if(binary.find("0") != string::npos)
            ret = (ret + 1) % MOD;
        
        return ret;
    }
};
