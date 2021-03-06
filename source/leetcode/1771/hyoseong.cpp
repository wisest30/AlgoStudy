class Solution {
public:
    string s;
    vector<vector<int>> dp;
    
    int recur(int l, int r) {
        if(l == r) return 0;
        if(l + 1 == r) return 1;

        auto& ret = dp[l][r];
        if(ret != -1) return ret;
        
        if(s[l] == s[r-1])
            ret = 2 + recur(l + 1, r - 1);
        else
            ret = max(recur(l + 1, r), recur(l, r - 1));
        
        return ret;
    }
    
    int longestPalindrome(string word1, string word2) {
        s = word1 + word2;
        dp = vector<vector<int>>(s.size() + 1, vector<int>(s.size() + 1, -1));
        
        auto ret = 0;
        for(auto i = 0; i < word1.size(); ++i)
            for(auto j = 0; j < word2.size(); ++j)
                if(word1[i] == word2[j])
                    ret = max(ret, 2 + recur(i + 1, word1.size() + j));
        
        return ret;
    }
};
