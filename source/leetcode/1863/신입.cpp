class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ret = 0;
        
        for(int i=0;i<(1<<nums.size());i++)
        {
            int xorSum = 0;
            
            for(int j=0;j<nums.size();j++)
            {
                if(i&(1<<j)) xorSum ^= nums[j];
            }
            
            ret += xorSum;
        }
        
        return ret;
    }
};
