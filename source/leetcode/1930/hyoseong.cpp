class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> A(26);
        for(auto i = 0; i < s.size(); ++i)
            A[s[i] - 'a'].push_back(i);
        
        int ret = 0;
        for(auto i = 0; i < 26; ++i) {
            if(A[i].size() < 2) continue;
            for(auto j = 0; j < 26; ++j) {
                if(A[j].empty()) continue;
                auto p = upper_bound(A[j].begin(), A[j].end(), A[i][0]);
                auto q = lower_bound(A[j].begin(), A[j].end(), A[i].back());
                if(p != q) ret++;
            }
        }
        
        return ret;
    }
};
