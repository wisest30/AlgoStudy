class Solution {
public:
    int getMaximumGenerated(int n) {
        
        int max_val = 0;
        
        if(n >= 1)
        {
            vector<int> nums(n+1);

            nums[0] = 0;
            nums[1] = 1;
            max_val = 1;

            for(int k = 2; k <= n; k++)
            {
                const int i = k / 2;
                if(k % 2 == 0)
                {
                    nums[k] = nums[i];
                }
                else
                {
                    nums[k] = nums[i] + nums[i + 1];
                }
                
                if(nums[k] > max_val)
                {
                    max_val = nums[k];
                }
            }
        }
        
        return max_val;
    }
};
