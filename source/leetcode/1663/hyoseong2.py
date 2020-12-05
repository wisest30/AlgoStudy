class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        z_cnt, r = divmod(k-n, 25)
        
        if z_cnt == n :
            return "z" * n
        else :
            return "a" * (n - z_cnt - 1) + chr(ord('a') + r) + "z" * z_cnt
