class Solution {
public:
    vector<int> dist;
    int speed, hoursBefore;
    vector<vector<int64_t>> dp;
    
    int64_t recur(int idx, int remain_skip) {
        if(idx == -1)
            return 0;
        
        auto& ret = dp[idx][remain_skip];
        if(ret != -1)
            return ret;
        
        ret = (recur(idx - 1, remain_skip) + dist[idx] + speed - 1) / speed * speed;
        if(remain_skip > 0)
            ret = min(ret, recur(idx - 1, remain_skip - 1) + dist[idx]);
        
        return ret;
    }
    
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        this->dist = dist;
        this->speed = speed;
        this->hoursBefore = hoursBefore;
        dp = vector<vector<int64_t>>(dist.size(), vector<int64_t>(dist.size(), -1));
        
        int n = dist.size();
        for(auto i = 0; i < n; ++i)
            if(recur(n-1, i) <= (int64_t)speed * hoursBefore)
                return i;
        
        return -1;
    }
};
