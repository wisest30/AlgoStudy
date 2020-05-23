class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        prefix = reduce(lambda s, x: s + [s[-1] ^ x], arr, [0])
        n = len(prefix)

        return sum(j - i - 1 for i in range(n) for j in range(i + 1, n)
                   if prefix[i] == prefix[j])
