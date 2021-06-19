class Solution {
public:
    int getMinCost(const string& s, const string& t) {
        int n = s.size();
        
        vector<int> A(n);
        for(auto i = 0; i < n; ++i)
            A[i] = s[i] == t[i];
        
        vector<int> partialSum(n+1);
        for(auto i = 1; i <= n; ++i)
            partialSum[i] = partialSum[i-1] + A[i-1];
        
        auto getOneCnt = [&](auto l, auto r) {
            return partialSum[r] - partialSum[l];
        };
        
        auto getZeroCnt = [&](auto l, auto r) {
            return r - l - getOneCnt(l, r);
        };
        
        auto ret = INT_MAX;
        for(auto i = 0; i < n; ++i) {
            bool needFlipLeft = (n - i) % 2;
            bool needFlipRight = i % 2;

            auto costLeft =  needFlipLeft ? getOneCnt(0, i) : getZeroCnt(0, i);
            auto costRight = needFlipRight ? getOneCnt(i, n) : getZeroCnt(i, n);
            
            ret = min(ret, costLeft + costRight);
        }
        
        return ret;
    }
    
    int minFlips(string s) {
        string t0, t1;
        for(auto i = 0; i < s.size(); ++i) {
            t0.push_back(i % 2 ? '1' : '0');
            t1.push_back(i % 2 ? '0' : '1');
        }
        
        return min(getMinCost(s, t0), getMinCost(s, t1));
    }
};
