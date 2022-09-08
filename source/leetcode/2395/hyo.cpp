class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i = 0; i + 1 < nums.size(); ++i) {
            int su = nums[i] + nums[i+1];
            if(s.count(su))
                return true;

            s.insert(su);
        }
        
        return false;
    }
};
