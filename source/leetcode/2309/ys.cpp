class Solution {
public:
    string greatestLetter(string s) {
        std::unordered_map<int, int> lower_cache;
        std::unordered_map<int, int> upper_cache;
        
        for (char c : s) {
            if (c < 'a') {
                lower_cache[c - 'A']++;
            } else {
                upper_cache[c - 'a']++;
            }
        }
        
        std::string res = "";
        
        for (size_t i = 0; i < 26; ++i) {
            if (lower_cache[i] > 0 && upper_cache[i] > 0) {
                res = char('A' + i);
            }
        }
        
        return res;   
    }
};
