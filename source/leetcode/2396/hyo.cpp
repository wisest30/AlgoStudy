class Solution {
public:
    bool isPalindrom(vector<int>& A) {        
        int n = A.size();
        for(auto i = 0; i < n / 2; ++i)
            if(A[i] != A[n - i - 1])
                return false;
        
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(auto p = 2; p <= n - 2; ++p) {
            vector<int> A;
            int x = n;
            while(x) {
                A.push_back(x % p);
                x /= p;
            }
            
            if(!isPalindrom(A))
                return false;
        }
        
        return true;
    }
};
