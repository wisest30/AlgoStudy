class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        if rounds[0] <= rounds[-1] :
            ret = list(range(rounds[0], rounds[-1] + 1))
        else :
            ret = list(range(rounds[0], n+1)) + list(range(1, rounds[-1] + 1))
            ret.sort()
        return ret
