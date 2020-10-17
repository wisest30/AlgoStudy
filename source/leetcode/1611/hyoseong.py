sys.setrecursionlimit(10 ** 9)
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        ret = 0
        while n :
            p = (n).bit_length() - 1
            if p == 0 :
                ret += 1
                break
            else :
                ret += 2 ** p
                n ^= 1 << p
                n ^= 1 << (p-1)
        return ret
                
