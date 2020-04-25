import sys
import threading
from collections import defaultdict

input = sys.stdin.readline
sys.setrecursionlimit(10**7)


def maxPaintPoint(n, pairs):
    graph = defaultdict(list)
    for a, b in pairs:
        graph[a].append(b)
        graph[b].append(a)

    scores = [0] * (n + 1)
    def score(v, parent):
        for c in graph[v]:
            if c != parent:
                scores[v] += score(c, v)
        scores[v] += 1
        return scores[v]

    score(1, None)
    maxPoint = sum(scores)

    def reroot(v, parent, point):
        nonlocal maxPoint

        maxPoint = max(maxPoint, point)
        for c in graph[v]:
            if c != parent:
                childScore, parentScore = scores[c], scores[v]
                scores[c], scores[v] = parentScore, parentScore - childScore
                delta = scores[c] + scores[v] - (childScore + parentScore)
                reroot(c, v, point + delta)
                scores[c], scores[v] = childScore, parentScore

    reroot(1, None, maxPoint)
    return maxPoint


def solve():
    n = int(input())
    pairs = [map(int, input().split()) for _ in range(n - 1)]
    print(maxPaintPoint(n, pairs))


solve()
threading.stack_size(1024 * 100000)
thread = threading.Thread(target=solve)
thread.start()
thread.join()
