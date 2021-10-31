class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size();
        for(auto i = 0; i < n; ++i)
            if(i % 10 == nums[i]) return i;
        return -1;
    }
};
