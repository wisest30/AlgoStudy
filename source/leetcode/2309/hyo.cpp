class Solution {
public:
    string greatestLetter(string s) {
        set<char> S(s.begin(), s.end());
        for(auto c = 'Z'; c >= 'A'; --c)
            if(S.count(c) && S.count(tolower(c)))
                return string(1, c);
        
        return "";
    }
};
