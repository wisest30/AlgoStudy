class Solution {
public:
    int n;
    vector<vector<int>> g;
    // return type : (node cnt, max_score, max_score_cnt)
    array<int64_t, 3> dfs(int cur) {
        int64_t cnt = 1, score = 1, max_score = 1, max_score_cnt = 0;
        for(auto nxt : g[cur]) {
            auto sub_ret = dfs(nxt);
            cnt += sub_ret[0];
            score *= sub_ret[0];
            
            if(sub_ret[1] == max_score)
                max_score_cnt += sub_ret[2];
            else if(sub_ret[1] > max_score)
                max_score = sub_ret[1], max_score_cnt = sub_ret[2];
        }

        if(cur)
            score *= n - cnt;
        
        if(score == max_score)
            ++max_score_cnt;
        else if(score > max_score)
            max_score = score, max_score_cnt = 1;
        
        return {cnt, max_score, max_score_cnt};
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        g = vector<vector<int>>(n);
        for(auto i = 1; i < n; ++i)
            g[parents[i]].push_back(i);
        return dfs(0)[2];
    }
};
