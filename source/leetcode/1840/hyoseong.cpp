class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& R) {
        if(R.empty()) return n-1;
        
        sort(R.begin(), R.end());
        
        vector<int> H(R.size());
        for(auto i = 0; i < H.size(); ++i) {
            if(i == 0) H[i] = R[i][0] - 1;
            else H[i] = min(R[i][1], H[i-1] + R[i][0] - R[i-1][0]);
        }
        for(auto i = (int)H.size() - 2; i >= 0; --i)
            H[i] = min(H[i], H[i+1] + R[i+1][0] - R[i][0]);

        long long ret = 0;
        for(auto i = 0; i < H.size(); ++i) {
            long long h = H[i];
            long long ph = i == 0 ? 0 : H[i-1];
            long long d = i == 0 ? R[i][0] - 1 : R[i][0] - R[i-1][0];
            auto candi = (h + ph + d) / 2;
            ret = max(ret, candi);
        }
        ret = max(ret, (long long)H.back() + n - R.back()[0]);
        
        return ret;
    }
};
