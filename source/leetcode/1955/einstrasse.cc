/* Problem : https://leetcode.com/contest/weekly-contest-252/problems/count-number-of-special-subsequences/
 * Solution : https://leetcode.com/problems/count-number-of-special-subsequences/discuss/1397896/Easy-C%2B%2B-solution-with-less-time
 * 
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
        /*
        a는 0으로만 이루어진 sequence중 길이가 1이상인 subsequence의 길이
        기존 *2를 하는 경우는 기존 선택한것에 하나더 추가하는 option이 생겼고
        +1를 하는 경우는 기존 선택한걸 다 빼고 새로 생긴것만 하나 선택하는 경우의 수

        b는 0과 1로만 이루어진 sequence중 순서가 맞고 각각 개수가 1개 이상인 subsequence의
        종류(갯수)이다.
        b는 마찬가지로 기존의 선택한거에서 새로운거 하나를 덧붙인 경우로 *2가 적용된다.
        a를 더하는거는 기존 선택한 1를 다 빼고 새로 생긴 1 하나만 고르는 경우에 앞에 0을
        고르는 경우를 곱해서 1*a이다

        c는 앞에것과 마찬가지로, *2하는 것은 새로 생긴 2를 선택하지 않았던 옵션(기존 c)에
        새로생긴 2를 하나 추가하기만 하는 경우 개수가 동일하게 나오며,
        새로생긴 2만 한개를 고르고 앞의 0과 1을 고르는 경우(b)를 곱해서 더한 것이다.
        */
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
