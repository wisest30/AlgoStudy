class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> M;
        for(auto i = 0; i < nums.size(); ++i)
            for(auto j = i+1; j < nums.size(); ++j)
                M[nums[i] * nums[j]]++;
        
        int ret = 0;
        for(auto& p : M)
            ret += p.second * (p.second - 1);
        return ret * 4;
    }
};
