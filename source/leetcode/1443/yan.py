class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        tree = defaultdict(list)
        for start, end in edges:
            tree[start].append(end)

        def dfs(n):
            res = 0
            for c in tree[n]:
                res += dfs(c)
            if n and (res > 0 or hasApple[n]):
                res += 2
            return res

        return dfs(0)
