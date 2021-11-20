class Solution {
public:
    int parent[1000+5];
    
    int find(int n)
    {
        if(parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }
    
    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        if(u > v) swap(u, v);
        parent[v] = u;
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        
        int temp[1000+5];
        
        for(int i=1;i<=n;i++) parent[i] = i;
        
        for(auto &request : requests)
        {
            memcpy(temp, parent, sizeof(temp));
            
            merge(request[0], request[1]);
            
            bool valid = true;
            
            for(auto &restriction : restrictions)
            {
                if(find(restriction[0]) == find(restriction[1])) 
                {
                    valid = false;
                    break;
                }
            }
            
            ans.push_back(valid);
            
            if(!valid) memcpy(parent, temp, sizeof(parent));
        }
        
        return ans;
    }
};
