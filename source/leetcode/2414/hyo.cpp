class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ret = 0, cnt = 0;
        for(auto i = 0; i < s.size(); ++i) {
            if(i && s[i] - s[i-1] == 1) ++cnt;
            else cnt = 1;
            
            ret = max(ret, cnt);
        }
        
        return ret;
    }
};
