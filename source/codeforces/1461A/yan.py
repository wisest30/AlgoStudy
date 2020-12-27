from bisect import bisect
from itertools import accumulate


def solve():
    n, q = map(int, input().split())
    array = list(map(int, input().split()))
    sums = [int(input()) for _ in range(q)]

    array.sort()
    prefixSum = [0] + list(accumulate(array))

    def totalSum(end, start):
        return prefixSum[end] - prefixSum[start]

    pool = set()

    def gather(start, end):
        total = totalSum(end, start)
        pool.add(total)

        if array[start] == array[end - 1]:
            return

        mid = (array[start] + array[end - 1]) // 2
        i = bisect(array, mid)
        gather(start, i)
        gather(i, end)

    gather(0, len(array))
    for s in sums:
        print('Yes' if s in pool else 'No')


for _ in range(int(input())):
    solve()
