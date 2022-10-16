class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ansTime = 0;
        int ans = -1;
        
        for(int i=0;i<logs.size();i++)
        {
            int workedTime = logs[i][1];
            if(i) workedTime = logs[i][1] - logs[i-1][1];
            
            if(workedTime > ansTime)
            {
                ansTime = workedTime;
                ans = logs[i][0];
            }
            else if(workedTime == ansTime && logs[i][0] < ans) ans = logs[i][0];
        }
        
        return ans;
    }
};
