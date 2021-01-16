class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int N = nums.size();
        vector<int> cumSum(nums.size());
        cumSum[0] = nums[0];
        
        for(int i=1;i<N;i++) cumSum[i] = cumSum[i-1] + nums[i];
        
        int ans = 0;
        
        for(int i=N-2;i>=1;--i)
        {
            int rightSum = cumSum[N-1] - cumSum[i];
            auto st = lower_bound(cumSum.begin(), cumSum.begin()+i, cumSum[i] - rightSum);
            auto ed = upper_bound(cumSum.begin(), cumSum.begin()+i, cumSum[i] - (cumSum[i]+1)/2);
            
            if(ed-st > 0) ans += ed-st;
            ans %= 1'000'000'007;
        }
        
        return ans;
    }
};
