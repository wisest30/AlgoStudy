class Solution {
public:
    int countHomogenous(string s) {
        constexpr int MOD = 1e9 + 7;
        long long ret = 0;
        int i = 0, j = 0;
        while(j < s.size()) {
            if(s[i] == s[j]) {
                j++;
                ret = (ret + j - i) % MOD;
            }
            else i++;
        }
        
        return ret;
    }
};
