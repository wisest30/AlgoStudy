class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ret = 0;
        for(auto i = 0; i < 2; ++i) {
            int x0 = startPos[i], x1 = homePos[i];
            auto& cost = i == 0 ? rowCosts : colCosts;
            if(x0 < x1) {
                for(auto x = x0 + 1; x <= x1; ++x)
                    ret += cost[x];
            } else {
                for(auto x = x1; x < x0; ++x)
                    ret += cost[x];
            }
        }
        
        return ret;
    }
};
