class Solution {
public:
    vector<int> edges;
    void dfs(int cur, int d, vector<int>& D) {
        if(D[cur] != -1)
            return;
        D[cur] = d;
        if(edges[cur] != -1)
            dfs(edges[cur], d + 1, D);
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        this->edges = edges;
        
        vector<int> D0(n, -1), D1(n, -1);
        dfs(node1, 0, D0);
        dfs(node2, 0, D1);
        
        int ret = -1, min_dis = INT_MAX;
        for(auto i = 0; i < n; ++i) 
            if(D0[i] != -1 && D1[i] != -1 && max(D0[i], D1[i]) < min_dis)
                min_dis = max(D0[i], D1[i]), ret = i;
        
        return ret;
    }
};
