class Solution {
public:
    int countValidWords(string sentence) {
        istringstream is(sentence);
        string s;
        int ret = 0;
        while(is >> s) {
            bool valid = true;
            bool h = false, p = false;
            for(auto i = 0; i < s.size(); ++i) {
                if(isdigit(s[i])) {
                    valid = false;
                    break;
                } else if(s[i] == '-') {
                    if(h || i == 0 || i + 1 == s.size() || !isalpha(s[i-1]) || !isalpha(s[i+1])) {
                        valid = false;
                        break;
                    }
                    h = true;
                } else if(p || s[i] == '.' || s[i] == '!' || s[i] == ',') {
                    if(i + 1 != s.size()) {
                        valid = false;
                        break;
                    }
                    p = true;
                }
            }
            if(valid)
                ++ret;
        }
        
        return ret;
    }
};
