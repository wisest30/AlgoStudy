class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        A = [i for i in range(len(number)) if number[i] == digit]
        return max([number[:i] + number[i+1:] for i in A])
