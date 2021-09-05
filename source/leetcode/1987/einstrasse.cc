class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        long long dp[2] = {0,}; //dp[i] => 마지막이 i인 unique good subsequence의 개수
        //leading zero는 없다고 침.
        bool hasZero = false;
        for (char c : binary) {
            if (c == '0') {
                hasZero = true;
                dp[0] = dp[0] + dp[1]; //기존에 맨 뒤에 0만 추가한 경우
                dp[0] %= MOD;
            } else {
                dp[1] = dp[0] + dp[1] + 1; //1는 1가 단독으로 추가된 경우?!
                dp[1] %= MOD;
            }
        }
        //hasZero는 0만 하나 덜렁 있는 경우임.
        return (dp[0]+dp[1] + hasZero) % MOD;
    }
};
