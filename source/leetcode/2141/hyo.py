class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        sort, su = sorted(batteries), sum(batteries)
        while sort[-1] > su // n : su, n = su - sort.pop(), n - 1
        return su // n
