class Solution:
    def countCollisions(self, directions: str) -> int:
        ret = r = s = 0
        for d in directions :
            if d == 'R' :
                r += 1
            elif d == 'L' and r + s :
                ret += r + 1
                r, s = 0, 1
            elif d == 'S' :
                ret += r
                r, s = 0, 1
        
        return ret
