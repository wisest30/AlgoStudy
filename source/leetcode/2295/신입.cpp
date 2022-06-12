class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> idxMap;
        
        for(int i=0;i<nums.size();i++) idxMap[nums[i]] = i;
        
        for(auto &operation : operations)
        {
            nums[idxMap[operation[0]]] = operation[1];
            int temp = idxMap[operation[0]];
            idxMap[operation[1]] = temp;
        }
        
        return nums;
    }
};
