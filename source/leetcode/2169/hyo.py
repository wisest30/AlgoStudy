class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        return 0 if num2 == 0 else self.countOperations(num2, num1 % num2) + num1 // num2
