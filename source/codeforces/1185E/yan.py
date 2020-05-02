from collections import defaultdict


def snakePositions(matrix):
    def find(traces, override=True):
        traces = [(x + 1, y + 1) for x, y in traces]
        def unique(points):
            return len(set(points)) == 1

        def increasing(points, override):
            if not override:
                return all(x + 1 == y for x, y in zip(points, points[1:]))

            return all(x < y for x, y in zip(points, points[1:]))

        if len(traces) == 1:
            return traces[0], traces[0]

        traces.sort()

        xs = [x for x, y in traces]
        ys = [y for x, y in traces]

        first, second = traces[0], traces[1]
        if first[0] == second[0]:
            if unique(xs) and increasing(ys, override):
                return traces[0], traces[-1]
        elif first[1] == second[1]:
            if unique(ys) and increasing(xs, override):
                return traces[0], traces[-1]

        return None, None

    points = defaultdict(list)
    m, n = len(matrix), len(matrix[0])
    for i in range(m):
        for j in range(n):
            if matrix[i][j] != '.':
                points[matrix[i][j]].append((i, j))

    if not points:
        return [] 

    maxChar = max(points)[0]

    start, end = find(points[maxChar], override=False)
    if not start:
        return None

    result = [(start, end)]
    for c in reversed(range(ord('a'), ord(maxChar))):
        char = chr(c)
        traces = points[char]
        if not traces:
            result.append(result[-1])
            continue
        start, end = find(traces)
        if start:
            result.append((start, end))
        else:
            return None

    return result[::-1]


def solve():
    n, m = map(int, input().split())
    matrix = [input() for _ in range(n)]

    positions = snakePositions(matrix)
    if positions is None:
        print('NO')
    else:
        print('YES')
        print(len(positions))
        for (x0, y0), (x1, y1) in positions:
            print(x0, y0, x1, y1)


for _ in range(int(input())):
    solve()
