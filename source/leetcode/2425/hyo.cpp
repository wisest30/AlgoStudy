class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        auto ret = 0;
        if(nums1.size() % 2) for(auto x : nums2) ret ^= x;
        if(nums2.size() % 2) for(auto x : nums1) ret ^= x;
        return ret;
    }
};
