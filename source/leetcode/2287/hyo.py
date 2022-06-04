class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        c0, c1 = Counter(s), Counter(target)
        return min(c0[key] // cnt for key, cnt in c1.items())
