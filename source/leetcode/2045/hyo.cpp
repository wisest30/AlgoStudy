class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            e[0]--, e[1]--;
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        auto D = vector<vector<int>>(2, vector<int>(n, INT_MAX));
        priority_queue<array<int, 2>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();
            d = -d;
            
            if(d == D[0][cur] || d == D[1][cur] || d > D[1][cur]) continue;
            if(D[0][cur] == INT_MAX) D[0][cur] = d;
            else if(D[1][cur] == INT_MAX) D[1][cur] = d;

            if(d / change % 2)
                d += change - d % change;
            
            for(auto nxt : g[cur]) {
                auto nxt_d = d + time;                
                pq.push({-nxt_d, nxt});
            }
        }
        
        return D[1][n-1];
    }
};
