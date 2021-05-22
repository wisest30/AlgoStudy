class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        auto ret = 0;
        for(auto i = 0; i < nums1.size(); ++i) {
            int p = lower_bound(nums2.rbegin(), nums2.rend(), nums1[i]) - nums2.rbegin();
            int j = (int)nums2.size() - p - 1;
            if(j < 0 || j < i) continue;
            ret = max(ret, j - i);
        }
        
        return ret;
    }
};
