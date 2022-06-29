class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for(auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        auto vals = vector<int>(n);
        vector<int> st(n), et(n);
        auto time = 0;
        function<void(int, int)> dfs = [&](auto cur, auto prev) {
            st[cur] = time++;

            vals[cur] = nums[cur];
            for(auto nxt : g[cur]) {
                if(nxt == prev) continue;
                dfs(nxt, cur);
                vals[cur] ^= vals[nxt];
            }
            
            et[cur] = time++;
        };
        
        dfs(0, -1);
                
        int ret = INT_MAX;
        for(auto i = 1; i < n; ++i) {
            for(auto j = i + 1; j < n; ++j) {
                vector<int> A(3);
                if(st[i] < st[j] && et[j] < et[i]) {
                    A[0] = vals[0] ^ vals[i];
                    A[1] = vals[i] ^ vals[j];
                    A[2] = vals[j];                    
                } else if(st[j] < st[i] && et[i] < et[j]) {
                    A[0] = vals[0] ^ vals[j];
                    A[1] = vals[j] ^ vals[i];
                    A[2] = vals[i];
                } else {
                    A[0] = vals[0] ^ vals[i] ^ vals[j];
                    A[1] = vals[i];
                    A[2] = vals[j];
                }
                
                sort(A.begin(), A.end());
                ret = min(ret, A.back() - A.front());
            }
        }
        
        return ret;
    }
};
