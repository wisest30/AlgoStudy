class Solution {
public:
    string greatestLetter(string s) {
        bool exist[256]{};
        
        for(char ch : s) exist[ch] = true;
        for(int i=25;i>=0;i--)
        {
            if(exist[i+'a'] && exist[i+'A']) return string(1, i+'A');
        }
        
        return "";
    }
};
