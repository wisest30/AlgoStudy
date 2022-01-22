class Solution {
public:
    int numberOfWays(string corridor) {
        constexpr int MOD = 1e9 + 7;
        int n = corridor.size(), ret = 1, i = 0;
        while(true) {
            int cnt = 0;
            while(i < n && cnt < 2) cnt += corridor[i++] == 'S';
            if(cnt < 2) return 0;
            long long mul = 1;
            while(i < n && corridor[i] == 'P') ++i, ++mul;
            if(i == n) break;
            else ret = ret * mul % MOD;
        }
        return ret;
    }
};
