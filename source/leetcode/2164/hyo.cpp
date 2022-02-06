class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> v[2];
        for(auto i = 0; i < nums.size(); ++i) 
            v[i % 2].push_back(nums[i]);
        
        sort(v[0].begin(), v[0].end());
        sort(v[1].rbegin(), v[1].rend());
        
        for(auto i = 0; i < nums.size(); ++i)
            nums[i] = v[i % 2][i / 2];
        
        return nums;
    }
};
