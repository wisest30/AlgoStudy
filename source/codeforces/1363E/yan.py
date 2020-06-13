from operator import add
from collections import defaultdict


def solve():
    n = int(input())

    nodes = {i: list(map(int, input().split())) for i in range(1, n + 1)}
    edges = [tuple(map(int, input().split())) for _ in range(n - 1)]

    tree = defaultdict(list)
    for x, y in edges:
        tree[x].append(y)
        tree[y].append(x)

    minCost = 0
    def dfs(x, parent):
        nonlocal minCost

        parentCost = nodes[parent][0]
        if nodes[x][0] > parentCost:
            nodes[x][0] = parentCost

        zero, one = 0, 0
        for y in tree[x]:
            if y == parent:
                continue
            z, o = dfs(y, x)
            zero, one = zero + z, one + o

        cost, b, c = nodes[x]

        if b ^ c:
            if c == 1:
                one += 1
            else:
                zero += 1

        swap = min(one, zero)
        minCost += swap * cost
        return zero - swap, one - swap

    if any(left for left in dfs(1, 1)):
        print(-1)
    else:
        print(minCost * 2)


solve()
