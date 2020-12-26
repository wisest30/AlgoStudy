class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        vector<vector<int>> newCuboids;
        
        newCuboids.push_back({0, 0, 0});
        
        for(auto &cuboid : cuboids) 
        {
            set<vector<int>> uniqueCuboid;
            
            uniqueCuboid.insert({cuboid[0], cuboid[1], cuboid[2]});
            uniqueCuboid.insert({cuboid[0], cuboid[2], cuboid[1]});
            uniqueCuboid.insert({cuboid[1], cuboid[0], cuboid[2]});
            uniqueCuboid.insert({cuboid[1], cuboid[2], cuboid[0]});
            uniqueCuboid.insert({cuboid[2], cuboid[0], cuboid[1]});
            uniqueCuboid.insert({cuboid[2], cuboid[1], cuboid[0]});
            
            for(auto it = uniqueCuboid.begin(); it != uniqueCuboid.end() ; it++) newCuboids.push_back(*it);
        }
        
        sort(newCuboids.begin(), newCuboids.end(),
            [&](vector<int> &a, vector<int> &b)
             {
                 if(a[0] != b[0]) return a[0] < b[0];
                 if(a[1] != b[1]) return a[1] < b[1];
                 return a[2] < b[2];
             });
        
        vector<int> ans(newCuboids.size());
        ans[0] = 0;
        int ret = 0;
        
        for(int i=1;i<newCuboids.size();i++)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(newCuboids[j][1] <= newCuboids[i][1] && newCuboids[j][2] <= newCuboids[i][2])
                {
                    ans[i] = max(ans[i], ans[j] + newCuboids[i][2]);
                }
            }
            
            ret = max(ret, ans[i]);
        }
        
        return ret;
    }
};
