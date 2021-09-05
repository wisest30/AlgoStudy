class Solution {
public:
    int dp[1<<14][16];
    int numbit(int n) {
        int ret = 0;
        for (int i=0; i < 15; i++) {
            if ((1<<i) & n) ret++;
        }
        return ret;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        vector<int> bits[15];
        for (int i=0; i < (1<<14); i++) {
            bits[numbit(i)].push_back(i);
        }
        memset(dp, -1, sizeof(dp));
        //dp[mask][sessionNum] => sessionNum으로 mask에 해당하는 일을 최적으로 처리했을 때, 남는 시간의 값
        dp[0][1] = sessionTime;
        for (int i=1; i<= tasks.size(); i++) { //예상되는 처리해야 하는 일 개수 겸 확인할 세션 수
            for (int j=0;j <= tasks.size(); j++) { //지금 처리한 일 개수
                for (int bit : bits[j]) {
                    for (int t=0; t < tasks.size(); t++) { //다음에 처리 할 일 찾기
                        if ((bit & (1<<t))) continue; //이미 처리한 일 skip
                        if (dp[bit][i] == -1) continue; //기존이 불가능했음
                        
                        int next_bit = (bit | (1<<t));
                        if (dp[bit][i] >= tasks[t]) { //이번 세션에서 처리 가능
                            if (dp[next_bit][i] == -1 || dp[next_bit][i] < dp[bit][i] - tasks[t]) {
                                dp[next_bit][i] = dp[bit][i] - tasks[t];
                            }
                        } else { //이번 세션에서 처리 불가능
                            if (dp[next_bit][i+1] == -1 || dp[next_bit][i+1] < sessionTime - tasks[t]) {
                                dp[next_bit][i+1] = sessionTime - tasks[t];
                            }
                        }
                        
                    }
                }
            }
        }
        for (int i=1; i<= tasks.size(); i++) {
            if (dp[(1<<tasks.size()) - 1][i] != -1) {
                return i;
            }
        }
        return -1;
        
    }
};
