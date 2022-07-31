class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        return s.size() - s.count(0);
    }
};
