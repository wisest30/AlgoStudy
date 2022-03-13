class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k == 0) return nums[0];
        else if(n == 1) return k % 2 ? -1 : nums[0];
        else if(k == 1) return nums[1];
        else if(k < n) return max(*max_element(nums.begin(), nums.begin() + k - 1), nums[k]);
        else if(k == n) return *max_element(nums.begin(), nums.begin() + n - 1);
        else return *max_element(nums.begin(), nums.end());
    }
};
