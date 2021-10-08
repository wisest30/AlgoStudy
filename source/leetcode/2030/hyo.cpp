class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.size();
        vector<int> rcnt(n+1);
        for(auto i = n-1; i >= 0; --i)
            rcnt[i] = rcnt[i+1] + (s[i] == letter);
        
        auto nxt_c = vector<vector<int>>(n+1, vector<int>(26, n));
        for(auto i = n-1; i >= 0; --i) {
            nxt_c[i] = nxt_c[i+1];
            nxt_c[i][s[i] - 'a'] = i;
        }
        
        int cnt = 0, cur = 0;
        string ret;
        while(ret.size() < k) {
            if(cnt + k - (int)ret.size() == repetition) {
                ret.push_back(letter);
                cur = nxt_c[cur][letter - 'a'] + 1;
                cnt++;
            } else {
                for(auto i = 0; i < 26; ++i) {
                    auto nxt = nxt_c[cur][i] + 1;
                    auto nxt_cnt = cnt + (i + 'a' == letter);
                    auto nxt_len = (int)ret.size() + 1;
                    if(nxt > n) continue;
                    if(n - nxt < k - nxt_len) continue;
                    if(nxt_cnt + rcnt[nxt] < repetition) continue;
                    ret.push_back(i + 'a');
                    cur = nxt, cnt = nxt_cnt;
                    break;
                }
            }
        }
        
        return ret;
    }
};
