class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& E) {
        constexpr int MOD = 1e9 + 7;
        auto edges = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
        for(auto& e : E) {
            e[0]--, e[1]--;
            edges[e[0]].push_back({e[1], e[2]});
            edges[e[1]].push_back({e[0], e[2]});
        }

        vector<int> D(n);
        auto visited = vector<bool>(n);
        auto q = priority_queue<pair<int, int>>();
        q.push({0, n-1});
        while(!q.empty()) {
            auto d = -q.top().first;
            auto cur = q.top().second;
            q.pop();
            
            if(visited[cur]) continue;
            visited[cur] = true;
            D[cur] = d;
            
            for(auto& p : edges[cur])
                q.push({-(d + p.second), p.first});
        }
        
        auto A = vector<int>(n);
        iota(A.begin(), A.end(), 0);
        sort(A.begin(), A.end(), [&](auto l, auto r) {
            return D[l] > D[r];
        });
        
        auto dp = vector<int>(n);
        dp[0] = 1;
        for(auto cur : A) {
            for(auto e : edges[cur]) {
                int nxt = e.first;
                if(D[nxt] < D[cur])
                    dp[nxt] = (dp[nxt] + dp[cur]) % MOD;
            }
        }
        
        auto ret = dp.back();
        return ret;
    }
};
