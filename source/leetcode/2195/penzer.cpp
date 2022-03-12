#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long minimalKSum(vector<int>& nums, int k) {
    long long ret = ((long long)k + 1) * (long long)k / 2;
    long long max = k;
    set<int> visited;

    sort(nums.begin(), nums.end());

    for (auto num : nums) {
      if (visited.find(num) != visited.end()) continue;
      visited.insert(num);

      if (num > k) break;

      k++;
      ret += k - num;
    }

    return ret;
  }
};