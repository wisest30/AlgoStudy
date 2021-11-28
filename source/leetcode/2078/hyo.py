class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        candi1 = max(i for i, c in enumerate(colors) if c != colors[0])
        candi2 = max(len(colors) - i - 1 for i, c in enumerate(colors) if c != colors[-1])
        return max(candi1, candi2)
