class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> M;
        for(auto i = 0; i < nums.size(); ++i)
            for(auto j = i+1; j < nums.size(); ++j)
                ret += 8 * M[nums[i] * nums[j]]++;
        
        return ret;
    }
};
