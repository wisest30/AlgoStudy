class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto& s : words) {
            auto t = s;
            reverse(t.begin(), t.end());
            if(s == t)
                return s;
        }
        
        return "";
    }
};
