class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        auto g = numsDivide[0];
        for(auto d : numsDivide)
            g = __gcd(g, d);
        
        sort(nums.begin(), nums.end());
        for(auto i = 0; i < nums.size(); ++i)
            if(g % nums[i] == 0)
                return i;
        
        return -1;
    }
};
