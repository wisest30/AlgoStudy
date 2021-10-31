class Solution {
public:
    static constexpr int dy[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
    static constexpr int dx[8] = {0, -1, 1, 0, -1, 1, -1, 1};
    int n;
    vector<vector<int>> NS, pos;
    vector<string> P;
    int dfs(vector<vector<int>>& cur, const vector<int>& d, int status) {
        if(status == (1 << n) - 1) {
            for(auto i = 0; i < n; ++i) {
                if(cur[i][0] == pos[i][0] && cur[i][1] == pos[i][1]) {
                    if(P[i] == "rook" && d[i] != 0) return 0;
                    else if(P[i] == "queen" && d[i] != 0) return 0;
                    else if(P[i] == "bishop" && d[i] != 4) return 0;
                }
            }
            
            return 1;
        }

        int ret = 0;
        for(auto ns : NS[status]) {
            bool success = true;
            for(auto i = 0; i < n; ++i) {
                if(ns & (1 << i)) continue;
                cur[i][0] += dy[d[i]];
                cur[i][1] += dx[d[i]];
                
                if(cur[i][0] < 0 || cur[i][0] >= 8 || cur[i][1] < 0 || cur[i][1] >= 8)
                    success = false;
            }

            for(auto i = 0; i < n; ++i)
                for(auto j = i+1; j < n; ++j)
                    if(cur[i] == cur[j]) success = false;
            
            if(success)
                ret += dfs(cur, d, ns);
            
            for(auto i = 0; i < n; ++i) {
                if(ns & (1 << i)) continue;
                cur[i][0] -= dy[d[i]];
                cur[i][1] -= dx[d[i]];
            }
        }
        
        return ret;
    }
    int countCombinations(vector<string>& pieces, vector<vector<int>>& pos) {
        for(auto& p : pos) p[0]--, p[1]--;
        n = pieces.size();
        P = pieces;
        this->pos = pos;
        
        vector<vector<int>> dir;
        int total = 1;
        for(auto i = 0; i < n; ++i) total *= 8;
        for(auto subset = 0; subset < total; ++subset) {
            vector<int> d, t;
            auto x = subset;
            for(auto i = 0; i < n; ++i) {
                d.push_back(x % 8);
                x /= 8;
                
                if(pieces[i] == "rook" && d.back() >= 4) {
                    d.clear();
                    break;
                } else if(pieces[i] == "bishop" && d.back() < 4) {
                    d.clear();
                    break;
                }
            }
            if(!d.empty())
                dir.push_back(d);
        }

        NS = vector<vector<int>>(1 << n);
        for(auto status = 0; status < (1 << n); ++status) {
            for(auto ns = 0; ns < (1 << n); ++ns) {
                bool success = true;
                for(auto i = 0; i < n; ++i) {
                    auto p = status & (1 << i);
                    auto q = ns & (1 << i);
                    if(p && !q) success = false;
                }
                if(success) NS[status].push_back(ns);
            }
        }
        
        int ret = 0;
        for(auto& d : dir) {
            ret += dfs(pos, d, 0);
        }
        
        return ret;
    }
};
