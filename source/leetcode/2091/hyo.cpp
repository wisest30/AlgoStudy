class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;
        
        auto a = max_element(nums.begin(), nums.end()) - nums.begin();
        auto b = min_element(nums.begin(), nums.end()) - nums.begin();
        if(a > b)
            swap(a, b);
        
        return min(b+1, min(n-a, a+1 + n-b));
    }
};
