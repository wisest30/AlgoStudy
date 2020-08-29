class Solution {
public:
    bool canDistance(vector<int>& position, int m, int targetDist)
    {
        int before = position[0];
        int curCount = 1;
        
        for(int i=1;i<position.size();i++)
        {
            if(position[i] - before >= targetDist)
            {
                before = position[i];
                curCount++;
            }
        }
        
        return curCount >= m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int lo = 0;
        int hi = position.back() - position.front();
        int ans = -1;
        
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            
            if(canDistance(position, m, mid))
            {
                lo = mid + 1;
                ans = mid;
            }
            else hi = mid - 1;
        }
        
        return ans;
    }
};
