class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        auto ret = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto num : nums)
            if(s.count(num + diff) && s.count(num + 2 * diff))
                ++ret;
        
        return ret;
    }
};
