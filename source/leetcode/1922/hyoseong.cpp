class Solution {
public:
    long long pow_mod(long long x, long long y, long long mod) {
        if(y == 0) return 1;
        else if(y % 2) return x * pow_mod(x, y-1, mod) % mod;
        else return pow_mod(x * x % mod, y / 2, mod);
    }
    
    int countGoodNumbers(long long n) {
        int64_t e = (n + 1) / 2, o = n / 2;
        
        constexpr long long MOD = 1e9 + 7;
        auto ret = pow_mod(5, e, MOD) * pow_mod(4, o, MOD) % MOD;
        return ret;
    }
};
