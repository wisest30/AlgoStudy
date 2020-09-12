class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int minusLen = INT_MIN;
        int plusLen = INT_MIN;
        int ans = 0;
        
        for(int num : nums)
        {
            int newMinusLen;
            int newPlusLen;
            
            if(num < 0) 
            {
                newMinusLen = max({plusLen+1, 1});
                if(minusLen == INT_MIN) newPlusLen = INT_MIN;
                else newPlusLen = minusLen+1;
            }
            else if(num > 0)
            {
                if(minusLen == INT_MIN) newMinusLen = INT_MIN;
                else newMinusLen = minusLen+1;
                newPlusLen = max({plusLen+1, 1});
            }
            else
            {
                newMinusLen = INT_MIN;
                newPlusLen = INT_MIN;
            }
            
            plusLen = newPlusLen;
            minusLen = newMinusLen;
            
            //printf("%d %d\n", plusLen, minusLen);
            
            if(plusLen > ans) ans = plusLen;
        }
        
        return ans;
    }
};
