class DisjointSet {
    vector<int> G;
public :
    DisjointSet(int n) : G(n)
    { iota(G.begin(), G.end(), 0); }

    int find(int x) {
        if(G[x] == x) return x;
        return G[x] == x ? x : G[x] = find(G[x]);
    }

    void merge(int x, int y) {
        int gx = find(x), gy = find(y);
        G[gy] = gx;
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DisjointSet ds(n);
        vector<bool> ret;
        
        auto possible = [&](auto x, auto y) {
            int gx = ds.find(x), gy = ds.find(y);
            for(auto& r : restrictions) {
                int g0 = ds.find(r[0]), g1 = ds.find(r[1]);
                if(gx == g0 && gy == g1 || gx == g1 && gy == g0)
                    return false;
            }
            
            return true;
        };
        
        for(auto& r : requests) {
            if(possible(r[0], r[1])) {
                ds.merge(r[0], r[1]);
                ret.push_back(true);
            }
            else
                ret.push_back(false);
        }
        
        return ret;
    }
};
