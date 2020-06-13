class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        graph = defaultdict(set)
        rev = set()
        for x, y in connections:
            rev.add((x, y))
            graph[x].add(y)
            graph[y].add(x)

        def dfs(x, p):
            return sum(((x, y) in rev) + dfs(y, x) for y in graph[x] if y != p)

        return dfs(0, -1)
