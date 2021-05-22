class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<long long> prefixSum(nums.size(), 0);
        vector<int> lastRightIdxes(nums.size(), nums.size());
        vector<int> lastLeftIdxes(nums.size(), -1);
        
        prefixSum[0] = nums[0];
        for(int i=1;i<nums.size();i++) prefixSum[i] = prefixSum[i-1] + nums[i];
        
        stack<int> idxes;
        
        for(int i=0;i<nums.size();i++)
        {
            while(!idxes.empty() && nums[idxes.top()] > nums[i])
            {
                lastRightIdxes[idxes.top()] = i;
                idxes.pop();
            }
            idxes.push(i);
        }
        
        while(!idxes.empty()) idxes.pop();
        
        for(int i=(int)nums.size()-1;i>=0;--i)
        {
            while(!idxes.empty() && nums[idxes.top()] > nums[i])
            {
                lastLeftIdxes[idxes.top()] = i;
                idxes.pop();
            }
            idxes.push(i);
        }
        
        long long ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            long long sum = prefixSum[lastRightIdxes[i]-1];
            if(lastLeftIdxes[i] != -1) sum -= prefixSum[lastLeftIdxes[i]];
            
            ans = max(ans, 1LL * sum * nums[i]);
        }
        
        return ans%(1'000'000'007);
    }
};
