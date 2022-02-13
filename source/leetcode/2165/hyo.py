class Solution:
    def smallestNumber(self, num: int) -> int:
        A = sorted(str(abs(num)), reverse = num < 0)
        if A[0] == '0' :
            for i in range(1, len(A)) :
                if A[i] != '0' :
                    A[0], A[i] = A[i], A[0]
                    break
        return int("".join(A)) * (1 if num >= 0 else -1)
