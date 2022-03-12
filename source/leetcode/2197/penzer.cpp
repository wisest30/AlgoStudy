#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> ret;
    int now = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int gcd = __gcd(now, nums[i]);
      if (gcd > 1) now = gcd * (now / gcd) * (nums[i] / gcd);
      else {
        if (ret.size() > 0) {
          int gcd2 = __gcd(ret.back(), now);
          while (gcd2 > 1) {
            now = gcd2 * (now / gcd2) * (ret.back() / gcd2);
            ret.pop_back();

            if (ret.size() == 0) break;
            gcd2 = __gcd(ret.back(), now);
          }
        }
        ret.push_back(now);
        now = nums[i];
      }
    }
    if (ret.size() > 0) {
      int gcd2 = __gcd(ret.back(), now);
      while (gcd2 > 1) {
        now = gcd2 * (now / gcd2) * (ret.back() / gcd2);
        ret.pop_back();

        if (ret.size() == 0) break;
        gcd2 = __gcd(ret.back(), now);
      }
    }
    ret.push_back(now);

    return ret;
  }
};