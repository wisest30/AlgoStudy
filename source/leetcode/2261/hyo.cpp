class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        
        for(auto i = 0; i < nums.size(); ++i) {
            int cnt = 0;
            vector<int> arr;
            for(auto j = i; j < nums.size(); ++j) {
                if(nums[j] % p == 0)
                    ++cnt;
                
                arr.push_back(nums[j]);
                
                if(cnt <= k)
                    s.insert(arr);
                else
                    break;
            }
        }
        
        return s.size();
    }
};