class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int mxCnt = 1;
            
        for(int i=0;i<(1<<n);i++)
        {
            int temp = 0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j)) temp |= nums[j];
            }                    
            
            if(temp > mx)
            {
                mx = temp;
                mxCnt = 1;
            }
            else if(temp == mx) mxCnt++;
        }
        
        return mxCnt;
    }
};
