class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        sort(nums.rbegin(), nums.rend());
        int total = 0;
        for(int i=0;i<nums.size();++i) total += nums[i];
        int ans_total = 0;
        for(int i=0;i<nums.size();++i)
        {
            ans_total += nums[i];
            ans.push_back(nums[i]);
            if(ans_total > total - ans_total) break;
        }
        return ans;
    }
};
