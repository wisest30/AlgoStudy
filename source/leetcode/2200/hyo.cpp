class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size(), i = 0, j = 0;
        vector<int> ret;
        while(i < n) {
            if(j + k < i)
                ++j;
            else if(nums[i] == key && j < min(n, i + k + 1))
                ret.push_back(j++);
            else
                ++i;
        }
        
        return ret;
    }
};
