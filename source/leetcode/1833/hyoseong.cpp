class Solution {
public:
    int maxIceCream(vector<int>& A, int c) {
        sort(A.begin(), A.end());
        
        auto su = 0;
        auto ret = 0;
        for(auto x : A) {
            if(su + x <= c)
                su += x, ret++;
            else
                break;
        }
        
        return ret;
    }
};
