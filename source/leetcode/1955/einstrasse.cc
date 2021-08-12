/* Problem : https://leetcode.com/contest/weekly-contest-252/problems/count-number-of-special-subsequences/
 * Solution : https://leetcode.com/problems/count-number-of-special-subsequences/discuss/1397896/Easy-C%2B%2B-solution-with-less-time
 * 왜 답이 되는지 모르겠음...;
 */
using ll = long long;

class Solution {
public:
    const ll MOD = 1e9+7;
    int countSpecialSubsequences(vector<int>& nums) {
        ll a,b,c;
        a = b = c = 0;
        //0 여러개중에 subsequence개수는 2^n - 1이다.
        // a_n+1 = a_n * 2 + 1의 점화식을 갖는다.
        for (int n : nums) {
            if (n == 0) {
                a = (a*2+1) % MOD;
            } else if (n == 1) {
                b = (b*2 + a) % MOD;
            } else {
                c = (c*2+b) % MOD;
            }
        }
        return c;
    }
};
