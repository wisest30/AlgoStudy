struct Element
{
    int v;
    int dist;
};

bool operator<(const Element &a, const Element &b)
{
    return a.dist > b.dist;
}

class Solution {
public:
    vector<int> adj[1'0000+5];
    int dist[2][1'0000+5];
    
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        for(auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        priority_queue<Element> pq;
        memset(dist, 0x7f, sizeof(dist));
        dist[0][1] = 0;
        pq.push({1, 0});
        
        while(!pq.empty())
        {
            Element cur = pq.top();
            pq.pop();
            
            if(cur.dist > dist[1][cur.v]) continue;
            
            for(auto &next : adj[cur.v])
            {
                int newCurDist = cur.dist;
                
                if((cur.dist/change)%2 == 1) newCurDist = change * (cur.dist/change+1);    
                
                if(newCurDist + time < dist[0][next])
                {
                    dist[0][next] = newCurDist + time;
                    pq.push({next, dist[0][next]});
                }
                else if(newCurDist + time > dist[0][next] && newCurDist + time < dist[1][next])
                {
                    dist[1][next] = newCurDist + time;
                    pq.push({next, dist[1][next]});
                }
            }
        }
        
        return dist[1][n];
    }
};
