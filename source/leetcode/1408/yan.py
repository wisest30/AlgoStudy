class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        words.sort(key=len)
        return [w for i, w in enumerate(words)
                if any(w in word for word in words[i + 1:])]
