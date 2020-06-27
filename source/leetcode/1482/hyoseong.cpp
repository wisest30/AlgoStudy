class Solution {
public:
    int minDays(vector<int>& A, int M, int K) {
        int n = A.size();
        long long l = 0, r = INT_MAX;
        while(l+1<r) {
            auto m = (l+r)/2;
            int cnt = 0, f_cnt=0;
            for(auto i = 0; i < n; ++i) {
                if(A[i] <= m) cnt++;
                else cnt=0;
                if(cnt >= K) cnt=0, f_cnt++;
            }
            if(f_cnt>=M) r=m;
            else l=m;
        }
        return r == INT_MAX ? -1:r;
    }
};
