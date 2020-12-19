class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ret = 0
        x = 1
        MOD = 10 ** 9 + 7
        s = len(bin(n)) - 2
        for i in range(n, 0, -1) :
            if i < (1 << (s - 1)) :
                s -= 1
            ret += i * x
            x <<= s
            x %= MOD
            ret %= MOD
        return ret
