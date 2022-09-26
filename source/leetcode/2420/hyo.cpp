class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> L(n, 1), R(n, 1);
        for(auto i = 1; i < n; ++i) 
            if(nums[i-1] >= nums[i])
                L[i] += L[i-1];
        
        for(int i = n-2; i >= 0; --i)
            if(nums[i] <= nums[i+1])
                R[i] += R[i+1];
        
        vector<int> ret;
        for(auto i = 1; i < n-1; ++i)
            if(L[i-1] >= k && R[i+1] >= k)
                ret.push_back(i);
        
        return ret;
    }
};