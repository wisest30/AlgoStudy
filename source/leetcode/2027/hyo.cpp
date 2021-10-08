class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size(), ret = 0;
        for(auto i = 0; i < n;) {
            if(s[i] == 'O') ++i;
            else ++ret, i += 3;
        }
        
        return ret;
    }
};
