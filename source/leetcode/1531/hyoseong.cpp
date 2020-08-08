namespace {
    int dp[101][101][27][101];
}
class Solution {
public:
    vector<pair<int, char>> A;
    
    int ff(int cnt) {
        if(!cnt) return 0;
        if(cnt == 1) return 1;
        return 1 + to_string(cnt).size();
    }
    
    int f(int start, int k, char c, int cnt) {
        if(start == A.size()) return ff(cnt);
        if(c == A[start].second) return f(start + 1, k, c, cnt + A[start].first);

        auto& ret = dp[start][k][c-'a'][cnt];
        if(ret != -1) return ret;
        ret = ff(cnt) + f(start+1, k, A[start].second, A[start].first);
        if(A[start].first <= k)
            ret = min(ret, f(start+1, k - A[start].first, c, cnt));
        else
            ret = min(ret, ff(cnt) + f(start+1, 0, A[start].second, A[start].first - k));
        return ret;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        A = vector<pair<int, char>>{};
        for(auto c : s) {
            if(!A.empty() && A.back().first == c) A.back().first++;
            else A.push_back({1, c});
        }
        
        return f(0, k, 'z'+1, 0);
    }
};
