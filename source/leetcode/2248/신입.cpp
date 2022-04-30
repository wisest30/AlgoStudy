class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        for(auto &num : nums) sort(num.begin(), num.end());
        
        vector<int> ans;
        
        for(int i=1;i<=1000;i++)
        {
            bool found = true;
            for(auto &num : nums)
            {
                auto it = lower_bound(num.begin(), num.end(), i);
                if(it == num.end() || *it != i)
                {
                    found = false;
                    break;
                }
            }
            
            if(found) ans.push_back(i);
        }
        
        return ans;
    }
};
