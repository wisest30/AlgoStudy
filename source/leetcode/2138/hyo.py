class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        return [s[i:i+k] + fill * (k - len(s[i:i+k])) for i in range(0, len(s), k)]
