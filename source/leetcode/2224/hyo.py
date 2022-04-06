class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        a, b, c, d = int(current[:2]), int(current[3:]), int(correct[:2]), int(correct[3:])
        if b <= d : return c - a + (d - b) // 15 + (d - b) % 15 // 5 + (d - b) % 5
        else : return c - 1 - a + (60 + d - b) // 15 + (60 + d - b) % 15 // 5 + (60 + d - b) % 5
