class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(1 for w in words if w.startswith(pref))
