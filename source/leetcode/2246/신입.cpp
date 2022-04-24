class Solution {
public:
    vector<int> adj[1'00000+5];
    string s;
    int ans;
    
    int UpdateLongestPath(int cur)
    {
        int firstMx = 0, secondMx = 0;
        
        for(int next : adj[cur])
        {
            int res = UpdateLongestPath(next);
            
            if(s[cur] != s[next])
            {
                if(res > firstMx)
                {
                    secondMx = firstMx;
                    firstMx = res;
                }
                else if(res > secondMx) secondMx = res;
            }
        }
        
        ans = max(ans, firstMx + secondMx + 1);    
        return firstMx + 1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        this->s = s;
        for(int i=1;i<parent.size();i++) adj[parent[i]].push_back(i);    
        UpdateLongestPath(0);
        return ans;
    }
};
