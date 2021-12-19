class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int cur = 0;
        long long ret = 0;
        for(auto i = 0; i < prices.size(); ++i) {
            if(i == 0 || prices[i] != prices[i-1] -1)
                cur = 1;
            else
                cur++;
            
            ret += cur;
        }
        
        return ret;
    }
};
