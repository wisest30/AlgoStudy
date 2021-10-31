class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> ps(n+1);
        for(auto i = 1; i <= n; ++i)
            ps[i] = ps[i-1] + (s[i-1] == '|');
        
        vector<int> A;
        for(auto i = 0; i < n; ++i)
            if(s[i] == '|') A.push_back(i);

        vector<int> ret;
        for(auto& q : queries) {
            int l = q[0], r = q[1];
            ++r;
            if(ps[r] - ps[l] < 2) ret.push_back(0);
            else {
                auto p = lower_bound(A.begin(), A.end(), l) - A.begin();
                p = A[p];
                auto q = lower_bound(A.begin(), A.end(), r) - A.begin() - 1;
                q = A[q];
                auto cnt = ps[r] - ps[l];
                ret.push_back((q + 1) - p - cnt);
            }
        }
        
        return ret;
    }
};
