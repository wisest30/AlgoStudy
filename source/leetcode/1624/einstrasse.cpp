class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        int idx[30];
        memset(idx, -1, sizeof(idx));
        for (int i=0; i < s.length(); i++) {
            char c = s[i];
            if (idx[c-'a'] == -1) {
                idx[c-'a'] = i;
            } else {
                ans = max(ans, i - idx[c-'a'] - 1);
            }
        }
        return ans;
    }
};