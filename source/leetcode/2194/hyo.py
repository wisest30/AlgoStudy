class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        return [chr(r) + str(c) for r in range(ord(s[0]), ord(s[3]) + 1) for c in range(int(s[1]), int(s[4]) + 1)]
