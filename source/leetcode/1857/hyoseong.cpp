class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<int> in_degree(n);
        vector<vector<int>> E(n);
        for(auto& e : edges) {
            E[e[0]].push_back(e[1]);
            in_degree[e[1]]++;
        }

        auto color_cnt = vector<vector<int>>(n, vector<int>(26));
        vector<int> order;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                order.push_back(i);
                color_cnt[i][colors[i] - 'a']++;
            }
        }

        for(auto i = 0; i < order.size(); ++i)
        {
            int cur = order[i];
            for(auto nxt : E[cur]) {
                for(auto j = 0; j < 26; ++j)
                    color_cnt[nxt][j] = max(color_cnt[nxt][j], color_cnt[cur][j]);

                if(--in_degree[nxt] == 0) {
                    order.push_back(nxt);
                    color_cnt[nxt][colors[nxt] - 'a']++;
                }
            }
        }

        if(order.size() != n)
           return -1;

        int ret = 0;
        for(auto& c : color_cnt)
            ret = max(ret, *max_element(c.begin(), c.end()));

        return ret;
    }
};
