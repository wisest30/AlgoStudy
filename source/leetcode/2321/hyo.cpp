class Solution {
public:
    int f(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> A(n);
        for(auto i = 0; i < n; ++i)
            A[i] = nums2[i] - nums1[i];
        
        vector<int> ps(n+1);
        for(auto i = 1; i <= n; ++i)
            ps[i] = ps[i-1] + A[i-1];
        
        int ret = 0, min_val = 0;
        for(auto i = 1; i <= n; ++i) {
            ret = max(ret, ps[i] - min_val);
            min_val = min(min_val, ps[i]);
        }
        
        ret += accumulate(nums1.begin(), nums1.end(), 0);
        return ret;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(f(nums1, nums2), f(nums2, nums1));
    }
};
