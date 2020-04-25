class Solution {
public:
    int numOfWays(int n) {
        long long patt0 = 6, patt1 = 6;
        for(int i=1; i<n; i++){
            long long npatt0 = 3*patt0+2*patt1;
            long long npatt1 = 2*patt0+2*patt1;
            patt0 = npatt0%((int)1e9+7);
            patt1 = npatt1%((int)1e9+7);
        }
        return (patt0+patt1)%((int)1e9+7);
    }
};
