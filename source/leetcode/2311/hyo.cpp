class Solution {
public:
    int longestSubsequence(string s, int k) {
        reverse(s.begin(), s.end());
        
        int ret = 0;
        for(auto c : s) {
            if(c == '0')
                ret++;
            else if(ret < 30 && (1 << ret) <= k)
                k -= 1 << ret++;
        }
        
        return ret;
    }
};
