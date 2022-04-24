struct Entity
{
    int val;
    int len;
};

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        tasks.push_back(1'000'000'001);
        
        vector<Entity> entities;
        
        int before = tasks[0];
        int conti = 1;
        
        for(int i=1;i<tasks.size();i++)
        {
            if(tasks[i] != before)
            {
                entities.push_back({before, conti});
                conti = 1;
            }
            else conti++;
            
            before = tasks[i];
        }
        
        int ans = 0;
        
        for(auto &entity : entities)
        {
            if(entity.len == 1) return -1;
            ans += entity.len/3;    
            if(entity.len%3) ans++;
        }
        
        return ans;
    }
};
