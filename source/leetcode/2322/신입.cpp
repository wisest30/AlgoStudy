class Solution {
public:
    int st[1000+5];
    int ed[1000+5];
    int treeXOR[1000+5];
    int visitNum;
    
    vector<int> adj[1000+5];
    vector<int> nums;
    
    void dfs(int cur, int parent)
    {
        st[cur] = visitNum++;
        treeXOR[cur] = nums[cur];
        
        for(auto &nxt : adj[cur])
        {
            if(nxt == parent) continue;
            dfs(nxt, cur);
            treeXOR[cur] ^= treeXOR[nxt];
        }
        
        ed[cur] = visitNum++;
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        for(auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        this->nums = nums;
        
        dfs(0, -1);
        
        int n = nums.size();
        int ans = INT_MAX;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(i == j) continue;
                
                int firstFrom = edges[i][0];
                int firstTo = edges[i][1];
                
                int secondFrom = edges[j][0];
                int secondTo = edges[j][1];
                
                if(st[firstFrom] > st[firstTo]) swap(firstFrom, firstTo);
                if(st[secondFrom] > st[secondTo]) swap(secondFrom, secondTo);
                
                if(st[firstTo] < st[secondTo] 
                   && ed[secondTo] < ed[firstTo])
                {
                    int largest = max({
                        treeXOR[0]^treeXOR[firstTo],
                        treeXOR[firstTo]^treeXOR[secondTo], 
                        treeXOR[secondTo]});
                    
                    int smallest = min({
                        treeXOR[0]^treeXOR[firstTo],
                        treeXOR[firstTo]^treeXOR[secondTo],
                        treeXOR[secondTo]});
                    
                    ans = min(ans, largest - smallest);
                }
                else if(st[secondTo] < st[firstTo]
                       && ed[firstTo] < ed[secondTo])
                {
                    continue;
                }
                else
                {
                    int largest = max({
                        treeXOR[0]^treeXOR[firstTo]^treeXOR[secondTo],
                        treeXOR[firstTo],
                        treeXOR[secondTo]});
                    
                    int smallest = min({
                        treeXOR[0]^treeXOR[firstTo]^treeXOR[secondTo],
                        treeXOR[firstTo],
                        treeXOR[secondTo]});
                    
                    ans = min(ans, largest - smallest);
                }
                
                //cout << i << " " << j << " " << ans << "\n";
            }
        }
        
        return ans;
    }
};
