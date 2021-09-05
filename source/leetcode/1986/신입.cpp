class Solution {
public:
    int N;
    int dp[1 << 14][15+5];
    
    int getDp(vector<int>& tasks, int sessionTime, int bit, int curTime)
    {
        if(curTime > sessionTime) return INT_MAX;
        if(bit == (1 << N) - 1) return 1;
        if(dp[bit][curTime] != -1) return dp[bit][curTime];
        
        int &ret = dp[bit][curTime] = INT_MAX;
        
        for(int i=0;i<tasks.size();i++)
        {
            if(bit & (1 << i)) continue;
            int curAdd = getDp(tasks, sessionTime, bit | (1<<i), curTime + tasks[i]);
            int nextAdd = 1 + getDp(tasks, sessionTime, bit | (1<<i), tasks[i]);
            ret = min({ret, curAdd, nextAdd});    
        }
        
        return ret;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        N = tasks.size();
        memset(dp, -1, sizeof(dp));
        return getDp(tasks, sessionTime, 0, 0);
    }
};
