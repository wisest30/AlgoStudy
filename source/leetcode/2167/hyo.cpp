class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        int cnt = count(s.begin(), s.end(), '1');
        vector<int> A(n+1), B(n+1);
        A[0] = B[0] = cnt * 2;
        for(auto i = 1; i <= n; ++i) {
            A[i] = 1 + A[i-1] - 2 * (s[i-1] == '1');
            B[i] = min(B[i-1], A[i]);
        }
        
        int ret = B.back(), add = 0;
        for(auto i = (int)s.size() - 1; i >= 0; --i) {
            s[i] == '0' ? ++add : --add;
            ret = min(ret, B[i] + add);
        }
        return ret;
    }
};
