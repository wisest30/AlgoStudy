class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        return len({w for w, cnt in Counter(words1).items() if cnt == 1}
                 & {w for w, cnt in Counter(words2).items() if cnt == 1})
