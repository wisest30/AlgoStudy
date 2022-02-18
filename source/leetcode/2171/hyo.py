class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        return sum(beans) - max([(len(beans) - i) * v for i, v in enumerate(sorted(beans))])
