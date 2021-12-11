class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> A;
        for(auto i = 0; i < n; ++i)
            A.push_back({i, nums[i]});
        
        sort(A.begin(), A.end(), [](auto& l, auto& r) {
            return l.second > r.second;
        });

        sort(A.begin(), A.begin() + k);
        
        vector<int> ret;
        for(auto i = 0; i < k; ++i)
            ret.push_back(A[i].second);
        
        return ret;
    }
};
