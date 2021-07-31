class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {        
        istringstream is(text);
        string word;
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int ret = 0;
        while(is >> word) {
            bool can = true;
            for(auto c : word) {
                if(broken.count(c)) {
                    can = false;
                    break;
                }
            }
            
            if(can)
                ret++;
        }
        
        return ret;
    }
};
