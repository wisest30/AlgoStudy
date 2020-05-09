from collections import defaultdict


def snakePositions(matrix):
    def find(traces):
        if len(traces) == 1:
            return traces[0], traces[0]

        traces.sort()
        xs, ys = zip(*traces)
        first, second = traces[0], traces[1]
        x, y = xs[0], ys[0]
        c = matrix[x][y]
        if first[0] == second[0]:
            if any(x != y for x, y in zip(xs, xs[1:])):
                return None, None
            if all(c <= matrix[x][y] for y in range(ys[0], ys[-1] + 1)):
                return traces[0], traces[-1]
        elif first[1] == second[1]:
            if any(x != y for x, y in zip(ys, ys[1:])):
                return None, None
            if all(c <= matrix[x][y] for x in range(xs[0], xs[-1] + 1)):
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

    result = []
    maxChar = max(points)[0]
    for c in reversed(range(ord('a'), ord(maxChar) + 1)):
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
            print(x0 + 1, y0 + 1, x1 + 1, y1 + 1)


for _ in range(int(input())):
    solve()
