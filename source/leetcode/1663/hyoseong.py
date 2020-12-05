class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ret = ["a"] * n
        cur = n
        
        for i in range(n-1, -1, -1) :
            if cur + 25 <= k :
                ret[i] = "z"
                cur += 25
            elif cur == k :
                break
            else :
                add = k - cur
                ret[i] = chr(ord(ret[i]) + add)
                cur += add
        
        return "".join(ret)
