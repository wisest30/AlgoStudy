from math import gcd
from functools import reduce


def solve():
    n, m = map(int, input().split())

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if len(a) == 1:
        res = [x + a[0] for x in b]
        print(*res)
        return

    a.sort()
    g = reduce(gcd, (x - a[0] for x in a[1:]))

    res = [gcd(x + a[0], g) for x in b]
    print(*res)


solve()
