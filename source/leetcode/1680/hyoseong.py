class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        
        cur = 0
        for i in range(1, n + 1) :
            l = len(bin(i)) - 2
            cur <<= l
            cur += i
            cur %= MOD
        
        return cur
