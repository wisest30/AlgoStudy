class Solution {
public:
    int longestBeautifulSubstring(string word) {
        for(auto& x : word) {
            if(x == 'a') x = 0;
            else if(x == 'e') x = 1;
            else if(x == 'i') x = 2;
            else if(x == 'o') x = 3;
            else x = 4;
        }
        
        int prev = -1, cnt = 0, ret = 0;
        for(auto x : word) {
            if(x < prev) {
                if(x == 0) prev = 0, cnt = 1;
                else prev = -1, cnt = 0;
            }
            else if(x == prev || x == prev + 1) cnt++, prev = x;
            else prev = -1, cnt = 0;
            
            if(x == 4) ret = max(ret, cnt);
        }
        
        return ret;
    }
};
