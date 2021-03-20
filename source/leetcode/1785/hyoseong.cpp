class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        auto su = accumulate(nums.begin(), nums.end(), 0ll);
        return (abs(goal - su) + limit - 1) / limit;
    }
};
