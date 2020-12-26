class Solution:
    def minPartitions(self, n: str) -> int:
        ret = 0
        for c in n :
            ret = max(ret, ord(c) - ord('0'))
        return ret
