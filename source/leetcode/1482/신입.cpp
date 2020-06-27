class Solution {
public:
    int getBouquetNum(vector<int>& bloomDay, int day, int k)
    {
        int bloomCount = 0;
        int ret = 0;
        
        for(int flowerDay : bloomDay)
        {
            if(flowerDay <= day) bloomCount++;
            else bloomCount = 0;
            
            if(bloomCount == k)
            {
                ret++;
                bloomCount = 0;
            }
        }
        
        return ret;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0;
        int high = -1;
        int ans = -1;
        
        for(int flowerDay : bloomDay) high = max(high, flowerDay);
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(getBouquetNum(bloomDay, mid, k) >= m)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ans;
    }
};
