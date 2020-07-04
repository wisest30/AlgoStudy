class Solution {
public:
    vector<int> avoidFlood(vector<int>& A) {
        int n = A.size();
        auto S = set<int>{};
        auto ret = vector<int>(n, 0);
        auto M = map<int, int>{};
        for(auto i = 0; i < n; ++i)
        {
            if(A[i]) {
                if(!M.count(A[i]) || M[A[i]] < 0) {
                    M[A[i]] = i;
                    ret[i] = -1;
                }
                else {
                    auto p = S.lower_bound(M[A[i]]);
                    if(p == S.end()) return {};
                    auto idx = *p;
                    ret[idx] = A[i];
                    M[A[i]] = i;
                    ret[i] = -1;
                    S.erase(idx);
                }
            }
            else {
                S.insert(i);
            }
        }

        for(auto i = 0; i < n; ++i)
            if(!ret[i])
                ret[i] = 1;
        return ret;
    }
};
