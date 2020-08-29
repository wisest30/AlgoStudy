class Solution:
    def minDays(self, n: int) -> int:
        A = collections.deque()
        A.append([n, 0])
        visited = set()
        while A :
            cur, d = A.popleft()
            if cur == 0 :
                return d
            if cur in visited :
                continue
            visited.add(cur)

            if cur > 0 :
                A.append([cur - 1, d + 1])
            if cur % 2 == 0 :
                A.append([cur // 2, d + 1])
            if cur % 3 == 0 :
                A.append([cur // 3, d + 1])

        return -1 # error
