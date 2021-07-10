namespace {
class Combination2 {
    using T = unsigned long long;
    T MOD;
    vector<T> fact;
public :
    Combination2() = default;
    Combination2(int n, T MOD = 0)
    : MOD(MOD), fact(n+1) {
        fact[0] = 1;
        for(auto i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
    }

    T pow_mod(long long x, long long y, long long mod) {
        auto ret=1ll;
        while (y) {
                if (y % 2)
                    ret = ret * x % mod;
                x =  x * x % mod;
                y /= 2;
            }
        return ret;
    }

    T nCr(int n, int r) {
        return fact[n] * pow_mod(fact[n-r], MOD - 2, MOD) % MOD * pow_mod(fact[r], MOD - 2, MOD) % MOD;
    }
};
}

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int n;
    vector<vector<int>> edges;
    Combination2 C;
    
    pair<long long, long long> dfs(int cur) {
        pair<long long, long long> ret;
        ret.first = 1, ret.second = 0;

        for(auto nxt : edges[cur]) {
            auto sub_ret = dfs(nxt);
            ret.second += sub_ret.second;
            ret.first = ret.first * sub_ret.first % MOD * C.nCr(ret.second, sub_ret.second) % MOD;
        }
        
        ret.second++;
        return ret;
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        n = prevRoom.size();
        C = Combination2(n + 1, MOD);

        edges.resize(n);
        for(auto i = 1; i < n; ++i)
            edges[prevRoom[i]].push_back(i);
        
        auto ret = dfs(0).first;
        return ret;
    }
};
