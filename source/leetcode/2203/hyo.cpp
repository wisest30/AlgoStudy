class Solution {
public:
    static constexpr long long inf = 1e10 + 10;
    vector<long long> get_min_d(int n, vector<vector<pair<int, long long>>>& g, int start) {        
        priority_queue<pair<long long, int>> q;
        q.push({0, start});
        
        vector<long long> D(n, inf);
        while(!q.empty()) {
            long long d = -q.top().first;
            int cur = q.top().second;
            q.pop();
            
            if(D[cur] != inf)
                continue;
            
            D[cur] = d;
            for(auto& e : g[cur])
                q.push({-(d + e.second), e.first});
        }
        
        return D;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, long long>>> g(n), bg(n);
        for(auto& e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            bg[e[1]].push_back({e[0], e[2]});
        }
        
        auto D0 = get_min_d(n, g, src1);
        auto D1 = get_min_d(n, g, src2);
        auto D2 = get_min_d(n, bg, dest);
        
        auto ret = D0[dest] + D1[dest];
        for(auto i = 0; i < n; ++i)
            ret = min(ret, D0[i] + D1[i] + D2[i]);

        return ret >= inf ? -1 : ret;
    }
};
