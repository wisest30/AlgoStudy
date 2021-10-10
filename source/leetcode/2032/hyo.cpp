class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> A(101);
        for(auto x : nums1) A[x] |= 1;
        for(auto x : nums2) A[x] |= 2;
        for(auto x : nums3) A[x] |= 4;
        
        vector<int> ret;
        for(auto i = 0; i <= 100; ++i)
            if(__builtin_popcount(A[i]) >= 2)
                ret.push_back(i);
        
        return ret;
    }
};
