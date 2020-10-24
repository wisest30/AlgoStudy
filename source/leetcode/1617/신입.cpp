class Solution {
public:
    vector<int> adj[15+5];
    int ans[15+5];
    int visited;
    int target;
    
    bool isSubTree(int input, int st)
    {
        visited = 0;
        target = input;
        dfs(st);
        return target == visited;
    }
    
    void dfs(int cur)
    {
        visited |= (1<<cur);
        for(auto &next : adj[cur])
        {
            if(visited&(1<<next)) continue;
            if((target&(1<<next)) == 0) continue;
            dfs(next);
        }
    }
    
    int getDiameter(int input, int st)
    {
        visited = 0;
        int maxNode = findMaxDistNode(input, st, 0).first;
        visited = 0;
        return findMaxDistNode(input, maxNode, 0).second;
    }
    
    pair<int, int> findMaxDistNode(int input, int st, int dist)
    {
        pair<int, int> ret = {st, dist};
        
        visited |= (1<<st);
        for(auto &next : adj[st])
        {
            if(visited&(1<<next)) continue;
            if((target&(1<<next)) == 0) continue;
            
            pair<int, int> res = findMaxDistNode(input, next, dist+1);
            if(res.second > ret.second) ret = res;
        }
        
        return ret;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        memset(ans, 0, sizeof(ans));
        
        for(auto &edge : edges)
        {
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        
        for(int i=0;i<(1<<n);i++)
        {
            int st = -1;
            int cnt = 0;
            
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    if(st == -1) st = j;
                    cnt++;
                }
            }
            
            if(cnt > 1)
            {
                bool res = isSubTree(i, st);
                if(res) ans[getDiameter(i ,st)]++;
            }
        }
        
        vector<int> ret;
        for(int i=1;i<n;++i) ret.push_back(ans[i]);
        
        return ret;
    }
};
