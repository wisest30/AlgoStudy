class Solution {
public:
    int maxConsecutiveAnswers(string A, int k) {
        int n = A.size();
        vector<int> t(n+1), f(n+1);
        for(auto i = 1; i <= n; ++i) {
            t[i] = t[i-1] + (A[i-1] == 'T');
            f[i] = f[i-1] + (A[i-1] == 'F');
        }
        
        auto check = [&](auto m) {
            for(auto i = 0; i + m <= n; ++i) {
                if(t[i+m] - t[i] <= k) return true;
                if(f[i+m] - f[i] <= k) return true;
            }
            
            return false;
        };
        
        int l = 0, r = n + 1;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            if(check(m)) l = m;
            else r = m;
        }
        
        return l;
    }
};
