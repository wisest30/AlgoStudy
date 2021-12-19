class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ret = []
        prev = 0
        for i in spaces :
            ret.append(s[prev:i])
            ret.append(' ')
            prev = i
        ret.append(s[prev:])
        
        return "".join(ret)
