class Solution {
    //2d dynamic programming
    int dp[1<<12][13]; // dp[bitmask][k] => k명의 워커가 bitmask에 해당하는 일들을 처리하는데 걸리는 최소 시간
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        memset(dp, 0, sizeof(dp));
        for (int i=1; i < (1<< jobs.size()); i++) {
            for (int j=0; j < jobs.size(); j++) {
                if ((1 << j) & i) {
                    for (int l=1; l <= k; l++)
                        dp[i][l] += jobs[j];
                }
            }
        }
        for (int w=2; w <= k; w++) {
            for (int bit=1; bit < (1<<jobs.size()); bit++) {
                for (int p = bit; p > 0; p = (p-1) & bit) {
                    int q = p ^ bit;
                    assert((p|q) == bit);
                    assert((p&q) == 0);
                    dp[bit][w] = min(dp[bit][w], max(dp[p][w-1], dp[q][1]));
                }
            }
        }
        return dp[(1<<jobs.size())-1][k];
        
    }
};
