class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        A = []
        for i in range(n+1) :
            if i < 2 :
                A.append(i)
            elif i % 2 == 0 :
                A.append(A[i // 2])
            else :
                A.append(A[i // 2] + A[i // 2 + 1])
        return max(A)
