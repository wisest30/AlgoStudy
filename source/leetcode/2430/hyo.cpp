class SumVecHash {
    vector<long long> ps, ps_mul;
    int MOD;
public:
    SumVecHash(vector<long long>& A, long long MOD) : ps(A.size() + 1), ps_mul(A.size() + 1), MOD(MOD) {
        auto random_address = []{char *pt = new char;delete pt;return uint64_t(pt);};
        const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
        mt19937_64 rng(SEED);

        unordered_map<long long, long long> cv_map;
        for(auto i = 1; i < ps.size(); ++i) {
            if(!cv_map.count(A[i-1])) cv_map[A[i-1]] = rng() % MOD;
            auto cur = cv_map[A[i-1]];
            
            ps[i] = (ps[i-1] + cur) % MOD;
            ps_mul[i] = (ps_mul[i-1] + cur * i % MOD) % MOD;
        }
    }
    
    long long get_hash(int left, int right) {
        long long a = (ps_mul[right] - ps_mul[left] + MOD) % MOD;
        long long b = left * (ps[right] - ps[left] + MOD) % MOD;
        return (a - b + MOD) % MOD;
    }
};

class Solution {
public:
    SumVecHash *svh;
    vector<int> dp;
    string s;
    int recur(int start) {
        if(start == s.size()) return 0;
        
        auto& ret = dp[start];
        if(ret != -1) return ret;
        ret = 1;
        
        for(auto len = 1; start + 2 * len <= s.size(); ++len)
            if(svh->get_hash(start, start + len) == svh->get_hash(start + len, start + 2 * len))
                ret = max(ret, recur(start + len) + 1);
        
        return ret;
    }
    
    int deleteString(string s) {
        this->s = s;
        dp = vector<int>(s.size(), -1);        
        
        vector<long long> A(s.size());
        for(auto i = 0; i < s.size(); ++i) A[i] = s[i] - 'a';
        svh = new SumVecHash(A, 1e9 + 7);
        
        auto ret = recur(0);
        return ret;
    }
};
