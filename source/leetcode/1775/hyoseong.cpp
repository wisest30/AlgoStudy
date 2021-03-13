class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int su1 = 0, su2 = 0;
        for(auto x : nums1) su1 += x;
        for(auto x : nums2) su2 += x;
        
        if(su1 > su2) swap(nums1, nums2);

        vector<int> D;
        for(auto x : nums1) D.push_back(6 - x);
        for(auto x : nums2) D.push_back(x - 1);
        sort(D.begin(), D.end());
        
        int ret = 0;
        auto diff = abs(su1 - su2);
        while(!D.empty() && diff > 0) {
            ret++;
            diff -= D.back();
            D.pop_back();
        }
        
        return diff <= 0 ? ret : -1;
    }
};
