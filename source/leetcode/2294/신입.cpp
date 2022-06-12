class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int st = nums[0];
        int ans = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] - st > k)
            {
                st = nums[i];
                ans++;
            }
        }
        
        return ans;
    }
};
