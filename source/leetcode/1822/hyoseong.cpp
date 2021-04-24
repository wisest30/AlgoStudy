class Solution {
public:
    int arraySign(vector<int>& nums) {
        auto ret = 1;
        for(auto x : nums)
            if(x == 0) ret = 0;
            else if(x < 0) ret *= -1;
        return ret;
    }
};
