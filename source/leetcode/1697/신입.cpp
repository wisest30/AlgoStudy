class Solution {
public:
    int parent[1'00000+5];
    
    int find(int u)
    {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        
        if(u == v) return;
        if(u > v) swap(u, v);
        parent[v] = u;
    }
    
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        
        
        auto compareVec = [] (const vector<int>& a, const vector<int>& b) -> bool
        {
            return a[2] < b[2];
        };
        
        for(int i=0;i<queries.size();i++) queries[i].push_back(i);
        for(int i=0;i<n;i++) parent[i] = i;
        sort(edgeList.begin(), edgeList.end(), compareVec);
        sort(queries.begin(), queries.end(), compareVec);
        
        int edgeListCur = 0;
        
        for(auto& thisQuery : queries)
        {
            int u = thisQuery[0];
            int v = thisQuery[1];
            int limit = thisQuery[2];
            int idx = thisQuery[3];
            
            while(edgeListCur < edgeList.size() && edgeList[edgeListCur][2] < limit)
            {
                merge(edgeList[edgeListCur][0], edgeList[edgeListCur][1]);
                edgeListCur++;
            }
            
            if(find(u) == find(v)) ans[idx] = true;
        }
        
        return ans;
    }
};
