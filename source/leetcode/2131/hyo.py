class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        ab = Counter([w for w in words if w[0] < w[1]])
        aa = Counter([w for w in words if w[0] == w[1]])
        ba = Counter([w for w in words if w[0] > w[1]])
        return sum([cnt // 2 * 4 for cnt in aa.values()]) \
            + any([cnt % 2 for cnt in aa.values()]) * 2 \
            + sum([min(ab[key], ba["".join(reversed(key))]) for key in ab]) * 4
