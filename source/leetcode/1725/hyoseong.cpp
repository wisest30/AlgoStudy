class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& A) {
        int max_len = 0;
        for(auto x : A) {
            max_len = max(max_len, min(x[0], x[1]));
        }
        
        int ret = 0;
        for(auto x : A) {
            if(min(x[0], x[1]) == max_len)
                ret++;
        }
        
        return ret;
    }
};
