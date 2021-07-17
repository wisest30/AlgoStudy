class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        constexpr int MOD = 1e9 + 7;
        int m = paths.size();
        if(m == 1) return paths[0].size();
        
        int min_sz = INT_MAX;
        for(auto& p : paths)
            min_sz = min(min_sz, (int)p.size());
        
        vector<string> HS;
        for(auto i = 0; i < m; ++i) {
            string s;
            for(auto x : paths[i]) {
                s += to_string(x) + ",";
            }
            HS.push_back(s);
        }
        
        auto check = [&](auto mm, auto q, bool real) {
            vector<set<int>> S(m);
            vector<int> A;
            for(auto i = 0; i < m; ++i) {
                int64_t h = 0;
                int64_t p = 1;
                for(auto j = 0; j < mm; ++j) {
                    h = h * q % MOD + paths[i][j];
                    h %= MOD;
                    if(j != mm - 1)
                        p = p * q % MOD;
                }
                S[i].insert(h);
                if(i == 0) A.push_back(h);
                for(auto j = mm; j < paths[i].size(); ++j) {
                    int64_t prev = paths[i][j - mm];
                    h = (h - prev * p % MOD + MOD) % MOD;
                    h = h * q % MOD + paths[i][j];
                    h %= MOD;
                    S[i].insert(h);
                    if(i == 0) A.push_back(h);
                }
            }
            
            for(auto j = 0; j < A.size(); ++j) {
                auto h = A[j];
                bool success = true;
                for(auto i = 1; i < m; ++i)
                    if(S[i].count(h) == 0) {
                        success = false;
                        break;
                    }
                
                if(success) {
                    if(!real)
                        return true;
                    
                    string s;
                    for(auto i = j; i - j < mm; ++i)
                        s += to_string(paths[0][i]) + ",";
                    
                    bool success = true;
                    for(auto i = 1; i < m; ++i) {
                        if(HS[i].find(s) == string::npos) {
                            success = false;
                            break;
                        }
                    }
                    
                    if(success) return true;
                }
            }
            
            return false;
        };
        
        int l = 0, r = min_sz + 1;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            if(check(m, 12345678ll, false) && check(m, 58372ll, true)) l = m;
            else r = m;
        }
        
        return l;
    }
};
