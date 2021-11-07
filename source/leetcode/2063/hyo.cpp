class Solution {
public:
    long long countVowels(string word) {
        auto check = [](auto c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        long long ret = 0;
        int n = word.size();
        for(auto i = 0; i < n; ++i) {
            if(check(word[i]))
                ret += (long long)(i + 1) * (n - i);
        }
        
        return ret;
    }
};
