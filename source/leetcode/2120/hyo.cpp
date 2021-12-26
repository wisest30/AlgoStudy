class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ret(m);
        for(auto i = 0; i < m; ++i) {
            int y = startPos[0], x = startPos[1];
            for(auto j = i; j < m; ++j) {
                if(s[j] == 'R') ++x;
                else if(s[j] == 'L') --x;
                else if(s[j] == 'U') --y;
                else ++y;
                
                if(y < 0 || y >= n || x < 0 || x >= n)
                    break;
                ++ret[i];
            }
        }
        
        return ret;
    }
};
