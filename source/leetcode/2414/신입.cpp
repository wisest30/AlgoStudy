class Solution {
public:
    int longestContinuousSubstring(string s) {
        int curLen = 1;
        int ans = 1;
        
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1] != 'z' && s[i] == s[i-1] + 1) curLen++;
            else curLen = 1;
            
            ans = max(ans, curLen);    
        }
        
        return ans;
    }
};
