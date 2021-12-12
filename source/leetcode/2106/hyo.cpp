class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> A(500001);
        for(auto& f : fruits)
            A[f[0]] = f[1];
        for(auto i = 1; i < A.size(); ++i)
            A[i] += A[i-1];
        
        auto f = [&](auto l, auto r) {
            return l == 0 ? A[r] : A[r] - A[l-1];
        };
        
        auto ret = 0;
        for(auto l = 0; l <= startPos; ++l) {
            auto d = startPos - l;
            
            auto remain = k - 2 * d;
            if(remain >= 0)
                ret = max(ret, f(l, startPos + remain));
            
            remain = k - d;
            if(remain >= 0)
                ret = max(ret, f(l, startPos + remain / 2));
        }
        
        return ret;
    }
};
