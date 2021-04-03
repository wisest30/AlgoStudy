class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ret = 0, candi = 0;
        for(auto i = 0; i < nums.size(); ++i) {
            if(i == 0 || nums[i-1] < nums[i]) candi += nums[i];
            else candi = nums[i];
            
            ret = max(ret, candi);
        }
        
        return ret;
    }
};
