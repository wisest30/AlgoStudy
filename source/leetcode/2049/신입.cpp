class Solution {
public:
    typedef long long ll;
    
    vector<int> adj[1'00000+5];
    ll n;
    ll ans;
    int ansCnt;
    
    ll getSubtreeSz(int cur, int parent)
    {
        ll score = 1;
        ll ret = 1;
        
        for(int next : adj[cur]) 
        {
            if(next == parent) continue;
            ll sz = getSubtreeSz(next, cur);
            
            score *= sz;
            ret += sz;
        }
        
        score *= max(1LL, n - ret);
        
        if(score > ans)
        {
            ans = score;
            ansCnt = 1;
        }
        else if(score == ans) ansCnt++;
        
        return ret;
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        
        for(int i=1;i<parents.size();i++)
        {
            adj[parents[i]].push_back(i);
            adj[i].push_back(parents[i]);
        }
        
        getSubtreeSz(0, -1);
        
        return ansCnt;
    }
};
