class Solution {
public:
    int maxIceCream(vector<int>& A, int c) {
        sort(A.begin(), A.end());
        
        long long su = 0;
        for(auto i = 0; i < A.size(); ++i) {
            su += A[i];
            if(su > c) return i;
        }
        
        return A.size();
    }
};
