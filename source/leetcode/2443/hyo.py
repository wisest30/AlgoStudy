class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        return any(i + int(str(i)[::-1]) == num for i in range(num + 1))
