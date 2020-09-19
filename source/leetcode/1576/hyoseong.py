class Solution:
    def modifyString(self, s: str) -> str:
        A = list('!' + s + '!')
        for i in range(1, len(A)-1) :
            if A[i] == '?' :
                for c in 'abc' :
                    if c not in (A[i-1], A[i+1]) :
                        A[i] = c
                        break
        return "".join(A[1:-1])
