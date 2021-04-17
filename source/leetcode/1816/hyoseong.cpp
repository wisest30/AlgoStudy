class Solution {
public:
    string truncateSentence(string s, int k) {
        istringstream is(s);
        
        string ret;
        is >> ret;
        for(auto i = 0; i < k - 1; ++i) {
            string add;
            is >> add;
            
            ret += " " + add;
        }
        
        return ret;
    }
};
