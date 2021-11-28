class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cur = capacity;
        int ans = 0;
        
        for(int i=0;i<plants.size();i++)
        {
            if(cur < plants[i])
            {
                ans += 2*i;
                cur = capacity;
            }
            
            cur -= plants[i];
            
            ans++;
        }
        
        return ans;
    }
};
