class Solution {
public:
    vector<int> tasks;
    int sessionTime;
    vector<vector<int>> dp;
    
    int recur(int subset, int remainTime) {
        if(subset == (1 << tasks.size()) - 1)
            return 0;
        
        auto& ret = dp[subset][remainTime];
        if(ret != -1)
            return ret;
        
        ret = INT_MAX;
        if(remainTime < sessionTime)
            ret = recur(subset, sessionTime) + 1;

        for(auto i = 0; i < tasks.size(); ++i) {
            if(subset & (1 << i)) continue;
            if(remainTime < tasks[i]) continue;
            ret = min(ret, recur(subset | (1 << i), remainTime - tasks[i]));
        }
        
        return ret;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        this->tasks = tasks, this->sessionTime = sessionTime;
        dp = vector<vector<int>>(1 << tasks.size(), vector<int>(sessionTime + 1, -1));
        
        return recur(0, 0);
    }
};
