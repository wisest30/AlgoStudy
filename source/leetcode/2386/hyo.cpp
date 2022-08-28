class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long positive_sum = 0;
        for(auto i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0)
                positive_sum += nums[i];
            else
                nums[i] = -nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        if(nums.size() > k)
            nums.resize(k);

        auto small_sums = vector<long long>{0};
        for(auto x: nums) {
            if(small_sums.size() >= k && x > small_sums.back())
                break;

            int n = small_sums.size();
            for(auto i = 0; i < n; ++i)
                small_sums.push_back(small_sums[i] + x);
            
            sort(small_sums.begin(), small_sums.end());
            if(small_sums.size() > k)
                small_sums.resize(k);
        }
        
        return positive_sum - small_sums[k - 1];
    }
};
