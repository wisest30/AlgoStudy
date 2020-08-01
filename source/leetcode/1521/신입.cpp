class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int nearestZeroBitIdx[21];
        int ans = INT_MAX;
        
        memset(nearestZeroBitIdx, -1, sizeof(nearestZeroBitIdx));
        
        for(int i=0;i<arr.size();i++)
        {
            set<int> eventIdx;
            
            for(int j=0;j<21;j++)
            {
                if(nearestZeroBitIdx[j] == -1) continue;
                eventIdx.insert(-nearestZeroBitIdx[j]);
            }
            
            int curVal = arr[i];
            int calc = abs(target - curVal);
            if(calc < ans) ans = calc;
            
            for(int targetIdx : eventIdx)
            {
                targetIdx = -targetIdx;
                curVal &= arr[targetIdx];
                int calc = abs(target - curVal);
                if(calc < ans) ans = calc;
            }
            
            for(int j=0;j<21;j++)
            {
                if((arr[i]&(1<<j)) == 0) nearestZeroBitIdx[j] = i;
            }
        }
        
        return ans;
    }
};
