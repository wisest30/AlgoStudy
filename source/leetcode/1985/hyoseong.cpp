class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](auto& l, auto& r) {
            if(l.size() != r.size())
                return l.size() > r.size();
            return l > r;
        });
        
        return nums[k-1];
    }
};
