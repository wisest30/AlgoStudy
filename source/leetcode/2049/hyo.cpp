class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<int64_t> cnts, scores;
    void dfs(int cur) {
        for(auto nxt : g[cur]) {
            dfs(nxt);
            cnts[cur] += cnts[nxt];
            scores[cur] *= cnts[nxt];
        }
        
        if(cur) scores[cur] *= n - cnts[cur];        
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        g = vector<vector<int>>(n);
        for(auto i = 1; i < n; ++i)
            g[parents[i]].push_back(i);
        
        cnts = scores = vector<int64_t>(n, 1);
        dfs(0);
        
        map<int64_t, int> counter;
        for(auto s : scores) counter[s]++;
        
        return counter.rbegin()->second;
    }
};
