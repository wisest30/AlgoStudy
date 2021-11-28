from bisect import bisect_left, bisect_right
class RangeFreqQuery:
    def __init__(self, arr: List[int]):
        self.A = [[] for _ in range(10001)]
        for i, v in enumerate(arr) :
            self.A[v].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        return bisect_right(self.A[value], right) - bisect_left(self.A[value], left)
