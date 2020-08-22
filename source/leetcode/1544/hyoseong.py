class Solution:
    def makeGood(self, s: str) -> str:
        ret = []
        for c in s :
            if ret and ret[-1].lower() == c.lower() and ret[-1] != c :
                ret.pop()
            else :
                ret.append(c)
        return "".join(ret)
