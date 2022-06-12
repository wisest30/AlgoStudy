class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> m;
        for(auto i = 0; i < nums.size(); ++i)
            m[nums[i]] = i;
        
        for(auto& o : operations)
            if(m.count(o[0]))
                nums[m[o[0]]] = o[1], m[o[1]] = m[o[0]];
        
        return nums;
    }
};
