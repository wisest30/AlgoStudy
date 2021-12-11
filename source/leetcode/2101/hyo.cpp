class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> g(n);
        for(auto i = 0; i < n; ++i) {
            for(auto j = 0; j < n; ++j) {
                if(i != j) {
                    long long dx = bombs[i][0] - bombs[j][0];
                    long long dy = bombs[i][1] - bombs[j][1];
                    long long d2 = dx * dx + dy * dy;
                    long long r = bombs[i][2];
                    long long r2 = r * r;
                    if(r2 >= d2)
                        g[i].push_back(j);
                }
            }
        }
        
        int ret = 0;
        for(auto start = 0; start < n; ++start) {
            auto st = vector<int>{start};
            auto visited = vector<bool>(n);
            auto cnt = 0;
            while(!st.empty()) {
                auto cur = st.back();
                st.pop_back();
                if(visited[cur]) continue;
                visited[cur] = true;
                ++cnt;
                for(auto nxt : g[cur])
                    st.push_back(nxt);
            }
            ret = max(ret, cnt);
        }
        
        return ret;
    }
};
