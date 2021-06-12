class Solution {
    int stoi(const string &str) {
        int ret = 0;
        for (const auto c : str) {
            ret = 10 * ret + c - 'a';
        }
        return ret;
    }
    
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        const int a = stoi(firstWord);
        const int b = stoi(secondWord);
        const int c = stoi(targetWord);
        return (a + b == c);
    }
};