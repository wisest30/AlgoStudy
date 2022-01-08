class Solution {
public:
    string capitalizeTitle(string title) {
        transform(title.begin(), title.end(), title.begin(), ::tolower);
        istringstream is(title);
        string s, ret;
        while(is >> s) {
            if(!ret.empty()) ret.push_back(' ');
            if(s.size() > 2) s[0] = ::toupper(s[0]);
            ret += s;
        }
        return ret;
    }
};
