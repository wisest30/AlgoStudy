class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        return next((i for i, s in enumerate(sentence.split(), 1)
                     if s.startswith(searchWord)), -1           )