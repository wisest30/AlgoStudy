struct edge
{
    int from;
    int to;
    int weight;
    int originIdx;
};

bool operator<(const edge &a, const edge &b)
{
    return a.weight < b.weight;
}

struct node
{
    int depth;
    int parentEdge;
};

class Solution {
public:
    node nodeInfo[100+5];
    int parent[100+5];
    vector<int> adj[100+5]; // store edgeIdx;
    
    int find(int u)
    {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        if(u > v) swap(u, v);
        parent[v] = u;
    }
    
    void dfs(vector<edge>& edges, int here, int depth, int parentEdge)
    {
        nodeInfo[here].depth = depth;
        nodeInfo[here].parentEdge = parentEdge;
        
        for(int nextEdgeIdx : adj[here])
        {
            if(nextEdgeIdx == parentEdge) continue;
            
            int next = edges[nextEdgeIdx].to;
            if(next == here) next = edges[nextEdgeIdx].from;
            
            dfs(edges, next, depth+1, nextEdgeIdx);
        }
    }
    
    void process(vector<edge>& edges, int thisEdgeIdx, vector<int>& pseudoCritical)
    {
        int from = edges[thisEdgeIdx].from;
        int to = edges[thisEdgeIdx].to;
        int targetWeight = edges[thisEdgeIdx].weight;
        
        if(nodeInfo[from].depth < nodeInfo[to].depth) swap(from, to);
        
        while(nodeInfo[from].depth != nodeInfo[to].depth)
        {
            int fromParentEdge = nodeInfo[from].parentEdge;
            if(edges[fromParentEdge].weight == targetWeight) 
            {
                pseudoCritical[thisEdgeIdx] = 1;
                pseudoCritical[fromParentEdge] = 1;
            }
            int next = edges[fromParentEdge].from;
            if(from == next) next = edges[fromParentEdge].to;
            from = next;
        }
        
        while(from != to)
        {
            int fromParentEdge = nodeInfo[from].parentEdge;
            int toParentEdge = nodeInfo[to].parentEdge;
            
            if(edges[fromParentEdge].weight == targetWeight) 
            {                
                pseudoCritical[thisEdgeIdx] = 1;
                pseudoCritical[fromParentEdge] = 1;
            }
            if(edges[toParentEdge].weight == targetWeight) 
            {
                pseudoCritical[thisEdgeIdx] = 1;
                pseudoCritical[toParentEdge] = 1;
            }
            
            int fromNext = edges[fromParentEdge].from;
            int toNext = edges[toParentEdge].from;
            
            if(fromNext == from) fromNext = edges[fromParentEdge].to;
            if(toNext == to) toNext = edges[toParentEdge].to;
            
            from = fromNext;
            to = toNext;
        }
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++) 
        {
            parent[i] = i;
            adj[i].clear();
        }
        memset(nodeInfo, 0, sizeof(nodeInfo));
        
        vector<edge> newEdges;
        vector<int> used;
        vector<int> pseudoCritical;
        
        for(int i=0;i<edges.size();i++)
        {
            newEdges.push_back({edges[i][0], edges[i][1], edges[i][2], i});
            used.push_back(0);
            pseudoCritical.push_back(0);
        }
        
        sort(newEdges.begin(), newEdges.end());
        int finishedEdgeCount = 0;
        
        for(int i=0;i<newEdges.size();i++)
        {
            if(find(newEdges[i].from) != find(newEdges[i].to))
            {   
                merge(newEdges[i].from, newEdges[i].to);
                adj[newEdges[i].from].push_back(i);
                adj[newEdges[i].to].push_back(i);
                used[i] = 1;
                finishedEdgeCount++;
            }
            if(finishedEdgeCount == n-1) break;
        }
        
        dfs(newEdges, 0, 0, -1);
        
        for(int i=0;i<newEdges.size();i++)
        {
            if(used[i] == 0) process(newEdges, i, pseudoCritical);
        }
        
        vector<vector<int>> ans = vector<vector<int>> (2, vector<int>(0));
        
        for(int i=0;i<pseudoCritical.size();i++)
        {
            if(used[i] == 0 && pseudoCritical[i] == 0) continue;
            ans[pseudoCritical[i]].push_back(newEdges[i].originIdx);
        }
        
        return ans;
    }
};
