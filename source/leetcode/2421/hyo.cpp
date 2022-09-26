class DisjointSet {
    vector<int> G, Gmax, Gcnt;
public :
    DisjointSet(int n, vector<int>& vals) : G(n), Gmax(n), Gcnt(n, 1)
    { 
        for(auto i = 0; i < n; ++i) {
            G[i] = i;
            Gmax[i] = vals[i];
        }
    }

    int find(int x) {
        if(G[x] == x) return x;
        return G[x] = find(G[x]);
    }

    bool merge(int x, int y) {
        int gx = find(x), gy = find(y);
        if(gx == gy) return false;
        G[gy] = gx;
        if(Gmax[gx] == Gmax[gy])
            Gcnt[gx] += Gcnt[gy];
        else if(Gmax[gx] < Gmax[gy])
            Gcnt[gx] = Gcnt[gy];
        Gmax[gx] = std::max(Gmax[gx], Gmax[gy]);

        return true;
    }

    int max(int x) { return Gmax[find(x)]; }
    int cnt(int x) { return Gcnt[find(x)]; }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        DisjointSet ds(n, vals);
        
        vector<vector<int>> G(n);
        for(auto& e : edges)
            vals[e[0]] <= vals[e[1]] ? G[e[1]].push_back(e[0]) : G[e[0]].push_back(e[1]);
        
        vector<int> O(n);
        iota(O.begin(), O.end(), 0);
        sort(O.begin(), O.end(), [&](auto l, auto r) { return vals[l] < vals[r];} );
        
        int ret = n;
        for(auto cur : O) {
            for(auto nxt: G[cur]) {
                auto cur_max = ds.max(cur), nxt_max = ds.max(nxt), cur_cnt = ds.cnt(cur), nxt_cnt = ds.cnt(nxt);
                if(ds.merge(cur, nxt))
                    if(cur_max == nxt_max) ret += cur_cnt * nxt_cnt;
            }
        }
        
        return ret;
    }
};