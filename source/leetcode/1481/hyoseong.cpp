class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        auto M = map<int, int>{};
        for(auto a : arr) M[a]++;
        auto A = vector<pair<int, int>>(M.begin(), M.end());
        sort(A.begin(), A.end(), [](auto& x, auto& y) {
            return x.second < y.second;
        });
        auto ret = 0;
        for(auto i = 0; i < A.size(); ++i) {
            if(k) {
                if(A[i].second > k) ret++;
                k -= min(k, A[i].second);
            }
            else ret++;
        }
        return ret;
    }
};
