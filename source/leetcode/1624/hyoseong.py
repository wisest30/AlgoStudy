class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        ret = -1
        D = dict()
        for i in range(len(s)) :
            if s[i] in D :
                ret = max(ret, i - D[s[i]] - 1)
            else :
                D[s[i]] = i
        return ret
