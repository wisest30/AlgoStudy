# o(N)
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        difference = arr[1] - arr[0]

        for i in range(1, len(arr)):
            if difference != (arr[i] - arr[i-1]) :
                return False

        return True
