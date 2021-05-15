namespace {
    class DisjointSet {
        vector<int> G, Gcnt;
    public :
        DisjointSet(int n) : G(n), Gcnt(n)
        { iota(G.begin(), G.end(), 0); }

        int find(int x) {
            if(G[x] == x) return x;
            return G[x] = find(G[x]);
        }

        bool merge(int x, int y) {
            int gx = find(x), gy = find(y);
            if(gx == gy) return false;
            G[gy] = gx;
            Gcnt[gx] += Gcnt[gy];
            return true;
        }

        int cnt(int x) { return Gcnt[find(x)]; }
    };
}

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int, int>> A;
        for(auto q : queries)
            A.push_back({q, A.size()});
        
        sort(A.begin(), A.end());
        
        DisjointSet ds(A.size() + 1);
        
        sort(intervals.begin(), intervals.end(), [](auto& l, auto& r) {
            return l[1] - l[0] < r[1] - r[0];
        });
        
        vector<int> ret(queries.size(), -1);
        for(auto& i : intervals) {
            auto p = lower_bound(A.begin(), A.end(), make_pair(i[0], 0)) - A.begin();
            while(p != A.size() && A[p].first <= i[1]) {
                if(ret[A[p].second] == -1)
                    ret[A[p].second] = i[1] - i[0] + 1;
                
                if(p == ds.find(p)) ds.merge(p+1, p);
                p = ds.find(p);
            }
        }
        
        return ret;
    }
};
