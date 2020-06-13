def minReorder(n: int, connections: List[List[int]]) -> int:
    connections.sort(key=lambda i: (i[0], i[1]))

    pp = {0}
    count = 0

    for start, end in connections:
        if start in pp and end not in pp:
            path.add(end)
            count += 1
        elif end in pp and start not in pp:
            path.add(start)

    return count
