class Solution:
    def maximumGroups(self, grades: List[int]) -> int:
        x = 1
        while x * (x + 1) // 2 <= len(grades) :
            x += 1
        return x - 1
