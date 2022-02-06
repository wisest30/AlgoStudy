class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> candi0(n+1);
        priority_queue<int> q0;
        for(auto i = 0; i < n; ++i) {
            candi0[0] += nums[i];
            q0.push(nums[i]);
        }
        for(auto i = n; i < 2 * n; ++i) {
            candi0[i - n + 1] = candi0[i - n] + nums[i];
            q0.push(nums[i]);
            candi0[i - n + 1] -= q0.top();
            q0.pop();
        }
        
        vector<long long> candi1(n+1);
        priority_queue<int, vector<int>, greater<int>> q1;
        for(auto i = 2 * n; i < 3 * n; ++i) {
            candi1[n] += nums[i];
            q1.push(nums[i]);
        }
        for(auto i = 2 * n - 1; i >= n; --i) {
            candi1[i - n] = candi1[i - n + 1] + nums[i];
            q1.push(nums[i]);
            candi1[i - n] -= q1.top();
            q1.pop();
        }
        
        long long ret = INT64_MAX;
        for(auto i = 0; i < candi0.size(); ++i)
            ret = min(ret, candi0[i] - candi1[i]);
        return ret;
    }
};
