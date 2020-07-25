struct pqEntry
{
    int node;
    double prob;
};

bool operator<(const pqEntry &a, const pqEntry &b)
{
    return a.prob < b.prob;
}

struct Edge
{
    int next;
    double prob;
};

class Solution {
public:
    vector<Edge> adj[10000+5];
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0;i<edges.size();++i)
        {
            auto& edge = edges[i];
            adj[edge[0]].push_back({edge[1], succProb[i]});
            adj[edge[1]].push_back({edge[0], succProb[i]});
        }
        
        priority_queue<pqEntry> pq;
        vector<double> prob(n, 0);
        prob[start] = 1;
        pq.push({start, 1});
        
        while(!pq.empty())
        {
            pqEntry cur = pq.top();
            pq.pop();
            
            if(cur.prob < prob[cur.node]) continue;
            
            for(auto& edge : adj[cur.node])
            {
                if(cur.prob * edge.prob > prob[edge.next])
                {
                    prob[edge.next] = cur.prob * edge.prob;
                    pq.push({edge.next, prob[edge.next]});
                }
            }
        }
        
        return prob[end];
    }
};
