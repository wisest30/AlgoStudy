class Solution:
    def kMirror(self, k: int, n: int) -> int:        
        ret = 0
        A = ['1']
        while n > 0 :
            a = int("".join(A), k)
            if str(a) == str(a)[::-1] :
                ret += a
                n -= 1
            
            l = len(A)
            for i in range(l // 2, l) :
                if int(A[i]) + 1 < k :
                    A[i] = A[-i-1] = str(int(A[i]) + 1)
                    break
                else :
                    A[i] = A[-i-1] = '0'
            else :
                A = ['0'] * (l + 1)
                A[0] = A[-1] = '1'
                
        return ret
