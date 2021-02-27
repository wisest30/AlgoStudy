class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        auto check = [&](long long m) {
            long long op_cnt = 0;
            for(auto n : nums)
                op_cnt += (n + m - 1) / m - 1;
            
            return op_cnt <= maxOperations;
        };
        
        long long l = 0, r = *max_element(nums.begin(), nums.end());
        while(l + 1 < r) {
            long long m = (l + r) / 2;
            if(check(m)) r = m;
            else l = m;
        }
        
        return r;
    }
};
