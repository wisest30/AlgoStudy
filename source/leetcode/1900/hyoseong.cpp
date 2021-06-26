class Solution {
public:
    set<int> getNext(int subset) {
        auto cnt = __builtin_popcount(subset);
        auto sz = cnt / 2;
        
        vector<int> A, B;
        for(auto i = 0; i < 30 && A.size() < sz; ++i)
            if(subset & (1 << i))
                A.push_back(i);
        for(auto i = 30; i >= 0 && B.size() < sz; --i)
            if(subset & (1 << i))
                B.push_back(i);
        
        set<int> ret;
        for(auto x = 0; x < (1 << sz); ++x) {
            auto y = subset;
            for(auto i = 0; i < sz; ++i)
                y -= (x & (1 << i)) ? (1 << A[i]) : (1 << B[i]);
            ret.insert(y);
        }
        
        return ret;
    }
    
    vector<int> earliestAndLatest(int n, int f, int s) {
        f--, s--;        
    }
};
