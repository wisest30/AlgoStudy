class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        long long inf = 1e11;
        vector<long long> cost(20, inf);
        for(auto& t : tires) {
            long long s = changeTime, r = 1;
            for(auto i = 1; i < cost.size(); ++i, r *= t[1]) {
                s += t[0] * r;
                cost[i] = min(cost[i], s);
                if(t[0] * r > changeTime + t[0])
                    break;
            }
        }
        
        vector<long long> dp(numLaps + 1, inf);
        dp[0] = 0;
        for(auto i = 1; i < cost.size(); ++i) {
            for(auto j = i; j < dp.size(); ++j)
                dp[j] = min(dp[j], dp[j-i] + cost[i]);
        }
        
        return dp.back() - changeTime;
    }
};
