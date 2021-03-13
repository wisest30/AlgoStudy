class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size();
        int m = toppingCosts.size();
        
        int max_subset = 1;
        for(auto i = 0; i < m; ++i)
            max_subset *= 3;
        
        int ret = baseCosts[0];
        for(auto b : baseCosts) {
            for(auto subset = 0; subset < max_subset; ++subset) {
                int candi = b;
                int x = subset;
                for(auto i = 0; i < m; ++i) {
                    candi += toppingCosts[i] * (x % 3);
                    x /= 3;
                }
                
                if(abs(candi - target) < abs(ret - target) ||
                   abs(candi - target) == abs(ret - target) && candi < ret)
                    ret = candi;
            }
        }
        
        return ret;
    }
};
