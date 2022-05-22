class Solution {
public:
    int percentageLetter(string s, char letter) {
        auto cnt = count(s.begin(), s.end(), letter);
        return 100 * cnt / s.size();
    }
};
