struct Edge
{
    int v;
    int tm;
};

bool operator<(const Edge &a, const Edge &b)
{
    return a.tm > b.tm;
};

class Solution {
public:
    vector<Edge> adj[1'00000+5];
    int minTime[1'00000+5];
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for(auto &meeting : meetings) 
        {
            adj[meeting[0]].push_back({meeting[1], meeting[2]});
            adj[meeting[1]].push_back({meeting[0], meeting[2]});
        }
        
        adj[0].push_back({firstPerson, 0});
        adj[firstPerson].push_back({0, 0});
        
        memset(minTime, 0x7f, sizeof(minTime));
        
        priority_queue<Edge> pq;
        pq.push({0, 0});
        minTime[0] = 0;
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            Edge cur = pq.top();
            pq.pop();
            
            if(cur.tm > minTime[cur.v]) continue;
            
            ans.push_back(cur.v);
            
            for(auto &nxt : adj[cur.v])
            {
                if(nxt.tm < cur.tm) continue;
                
                if(nxt.tm < minTime[nxt.v])
                {
                    minTime[nxt.v] = nxt.tm;
                    pq.push({nxt.v, nxt.tm});    
                }
            }
        }
        
        return ans;
    }
};
