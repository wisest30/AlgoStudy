class Solution {
public:
    int numSub(string s) {
        constexpr int MOD = 1e9+7;
        long long ret=0, cnt=0, n=s.size();
        for(auto i = 0; i < n; ++i) {
            s[i] == '1' ? ++cnt:cnt=0;
            ret = (ret + cnt) % MOD;
        }
        return ret;
    }
};
