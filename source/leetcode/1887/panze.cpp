#define ull unsigned long long
#define uint unsigned int

class Solution {
public:
  int reductionOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());

    int ans = 0;
    int prev = nums[0];
    int cnt = 0;

    for (auto num : nums) {
      if (prev != num) {
        ans += cnt;
        prev = num;
      }
      ++cnt;
    }

    return ans;
  }
};
