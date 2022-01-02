class Solution {
public:
    int maximumInvitations(vector<int>& A) {
        int ret = 0, n = A.size();
        vector<vector<int>> bg(n);
        for(auto i = 0; i < n; ++i) bg[A[i]].push_back(i);
        vector<bool> visited(n), inpath(n);
        vector<int> time(n);
        auto ct = 1;
        function<void(int)> dfs = [&](auto cur) {
            visited[cur] = inpath[cur] = true, time[cur] = ct++;
            auto nxt = A[cur];
            if(!visited[nxt]) dfs(nxt);
            if(inpath[nxt]) ret = max(ret, time[cur] - time[nxt] + 1);
            inpath[cur] = false;
        };
        for(auto i = 0; i < n; ++i) if(!visited[i]) dfs(i);
        function<int(int)> dfs2 = [&](auto cur) {
            int ret = 1;
            for(auto nxt : bg[cur]) if(nxt != A[cur]) ret = max(ret, dfs2(nxt) + 1);
            return ret;
        };
        int ret2 = 0;
        for(auto i = 0; i < n; ++i) if(i == A[A[i]] && i < A[i]) ret2 += dfs2(i) + dfs2(A[i]);
        return max(ret, ret2);
    }
};
