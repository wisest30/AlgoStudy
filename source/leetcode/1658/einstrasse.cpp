class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = 987654321;
        vector<int> sum;
        sum.push_back(0);
        for (int i : nums) {
            sum.push_back(sum.back() + i);
        }
        int back = 0;
        int cnt = 0;
        int ptr = nums.size();
        while (ptr > 0) {
            int pos = lower_bound(sum.begin(), sum.begin() + ptr, x - back) - sum.begin();
            if (sum[pos] == x - back) {
                ans = min(ans, cnt + pos);
            }
            back += nums[--ptr];
            cnt++;
        }
        return ans == 987654321 ? -1 : ans;
        
    }
};
