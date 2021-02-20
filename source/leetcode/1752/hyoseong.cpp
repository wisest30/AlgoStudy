class Solution {
public:
    bool check(vector<int>& nums) {
        auto sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        for(auto i = 0; i < (int)nums.size(); ++i) {
            auto rotated = nums;
            rotate(rotated.begin(), rotated.begin() + i, rotated.end());
            
            if(rotated == sorted)
                return true;
        }
        
        return false;
    }
};
