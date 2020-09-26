class Solution:
    def unhappyFriends(self, n: int, PF: List[List[int]], pairs: List[List[int]]) -> int:
        P = [0] * n
        for u, v in pairs :
            P[u] = v
            P[v] = u
        
        A = [[0] * n for _ in range(n)]
        for i in range(n) :
            for j in range(len(PF[i])) :
                A[i][PF[i][j]] = j
        
        ret = 0
        for i in range(n) :
            x = A[i][P[i]]
            for j in range(n) :
                if i == j :
                    continue
                if x <= A[i][j] :
                    continue
                y = A[j][P[j]]
                if y <= A[j][i] :
                    continue
                ret += 1
                break
        return ret
