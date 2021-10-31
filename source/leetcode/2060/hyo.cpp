class Solution {
public:
    bool dp[41][41][2010];
    static constexpr int M = 1005;
    
    bool possiblyEquals(string s1, string s2) {
        dp[0][0][M] = true;
        
        auto propagate1 = [&](auto i1, auto i2, auto d) {
            if(isalpha(s1[i1]))
                dp[i1+1][i2][d+1] = true;
            int cnt = 0;
            for(auto j = 0; j < 3; ++j) {
                if(i1 + j >= s1.size() || isalpha(s1[i1 + j])) break;
                cnt = cnt * 10 + s1[i1+j] - '0';
                dp[i1+j+1][i2][d+cnt] = true;
            }
        };

        auto propagate2 = [&](auto i1, auto i2, auto d) {
            if(isalpha(s2[i2]))
                dp[i1][i2+1][d-1] = true;
            int cnt = 0;
            for(auto j = 0; j < 3; ++j) {
                if(i2 + j >= s2.size() || isalpha(s2[i2 + j])) break;
                cnt = cnt * 10 + s2[i2+j] - '0';
                dp[i1][i2+j+1][d-cnt] = true;
            }
        };
        
        auto propagate12 = [&](auto i1, auto i2, auto d) {
            if(isalpha(s1[i1]) && s1[i1] == s2[i2])
                dp[i1+1][i2+1][d] = true;
            int cnt = 0;
            for(auto j = 0; j < 3; ++j) {
                if(i1 + j >= s1.size() || isalpha(s1[i1 + j])) break;
                cnt = cnt * 10 + s1[i1+j] - '0';
                dp[i1+j+1][i2][d+cnt] = true;
            }
            cnt = 0;
            for(auto j = 0; j < 3; ++j) {
                if(i2 + j >= s2.size() || isalpha(s2[i2 + j])) break;
                cnt = cnt * 10 + s2[i2+j] - '0';
                dp[i1][i2+j+1][d-cnt] = true;
            }
        };
        
        for(auto i1 = 0; i1 <= s1.size(); ++i1) {
            for(auto i2 = 0; i2 <= s2.size(); ++i2) {
                for(auto d = 0; d < 2010; ++d) {
                    if(dp[i1][i2][d]) {
                        if(d < M && i1 < s1.size()) propagate1(i1, i2, d);
                        else if(d == M && i1 < s1.size() && i2 < s2.size()) propagate12(i1, i2, d);
                        else if(d > M && i2 < s2.size()) propagate2(i1, i2, d);
                    }
                }
            }
        }
        
        return dp[s1.size()][s2.size()][M];
    }
};
