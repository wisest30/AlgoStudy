class Solution {
public:

    vector<int> answer;
    string labels;
    vector<vector<int>> edges;
    vector<int> dfs(int cur, int par) {
        auto ret = vector<int>(26);
        ret[labels[cur] - 'a']++;
        for(auto& e : edges[cur]) {
            if(e == par) continue;
            auto sub_ret = dfs(e, cur);
            for(auto i = 0; i < 26; ++i) ret[i] += sub_ret[i];
        }
        answer[cur] = ret[labels[cur] - 'a'];
        return ret;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->answer = vector<int>(n);
        this->labels = labels;
        this->edges = vector<vector<int>>(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            this->edges[u].push_back(v);
            this->edges[v].push_back(u);
        }
        dfs(0, -1);
        return answer;
    }
};
