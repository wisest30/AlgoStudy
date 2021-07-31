class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    for (char c = 'a'; c <= 'z'; ++c) broken_letter[c] = false;
    for (auto c : brokenLetters) broken_letter[c] = true;

    bool broken_word = false;
    int ret = 0;
    for (auto c : text) {
      if (c == ' ') {
        ret += !broken_word;
        broken_word = false;
        continue;
      } else if (broken_word) {
        continue;
      }

      if (broken_letter[c]) {
        broken_word = true;
      }
    }
    return ret + !broken_word;
  }
private:
  bool broken_letter[256];
};