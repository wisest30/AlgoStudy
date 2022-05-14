class Solution {
public:
    vector<int> dp;
    string pressedKeys;
    long long recur(int i) {
        constexpr int MOD = 1e9 + 7;
        int n = pressedKeys.size();
        if(i == n)
            return 1;
        
        auto& ret = dp[i];
        if(ret != -1)
            return ret;
        
        ret = recur(i+1);
        for(auto j = 2; j < 5; ++j) {
            if(i + j - 1 >= n || pressedKeys[i] != pressedKeys[i + j - 1])
                break;
            if(j == 4 && pressedKeys[i] != '7' && pressedKeys[i] != '9')
                break;
            ret = (ret + recur(i + j)) % MOD;
        }
        
        return ret;
    }
    
    int countTexts(string pressedKeys) {
        dp = vector<int>(pressedKeys.size(), -1);
        this->pressedKeys = pressedKeys;
        
        auto ret = recur(0);
        return ret;
    }
};
