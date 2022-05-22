class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end());
        
        int n = stockPrices.size();
        int ret = n - 1;
        for(auto i = 1; i + 1 < n; ++i) {
            auto dx0 = stockPrices[i][0] - stockPrices[i-1][0];
            auto dy0 = stockPrices[i][1] - stockPrices[i-1][1];
            auto dx1 = stockPrices[i+1][0] - stockPrices[i][0];
            auto dy1 = stockPrices[i+1][1] - stockPrices[i][1];
            if((long long)dy0 * dx1 == (long long)dx0 * dy1)
                --ret;
        }
        
        return ret;
    }
};
