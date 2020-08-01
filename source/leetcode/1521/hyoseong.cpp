class Solution {
public:
    int closestToTarget(vector<int>& A, int t) {
        auto ret = INT_MAX;
        auto B = vector<int>{};
        for(auto i = 0; i < A.size(); ++i) {
            ret = min(ret, abs(t - A[i]));
            auto nxt_B = vector<int>{A[i]};
            for(auto j = 0; j < B.size(); ++j) {
                auto x = nxt_B.back() & B[j];
                if(x != nxt_B.back()) nxt_B.push_back(x);
                ret = min(ret, abs(t - x));
            }
            swap(B, nxt_B);
        }
        return ret;
    }
};
