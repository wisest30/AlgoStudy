class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        order = sorted(range(len(plantTime)), key = lambda x : -growTime[x])
        A = list(itertools.accumulate(map(lambda x : plantTime[x], order)))
        return max([A[i] + growTime[order[i]] for i in range(len(order))])
