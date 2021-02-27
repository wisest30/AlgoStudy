class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n+1);
        auto M = vector<vector<bool>>(n+1, vector<bool>(n+1));
        for(auto& e : edges) {
            degree[e[0]]++, degree[e[1]]++;
            M[e[0]][e[1]] = M[e[1]][e[0]] = true;
        }
        
        int ret = INT_MAX;
        for(auto i = 1; i <= n; ++i)
            for(auto j = i+1; j <= n; ++j)
                if(M[i][j])
                    for(auto k = j + 1; k <= n; ++k)
                        if(M[j][k] && M[k][i])
                            ret = min(ret, degree[i] + degree[j] + degree[k] - 6);
        
        if(ret == INT_MAX) ret = -1;
        return ret;
    }
};
