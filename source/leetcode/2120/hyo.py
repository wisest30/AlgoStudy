class Solution:
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        m = len(s)
        ret = [0] * m
        
        for i in range(m) :
            y, x = startPos
            for j in range(i, m) :
                if s[j] == 'R' :
                    ny, nx = y, x + 1
                elif s[j] == 'L' :
                    ny, nx = y, x - 1
                elif s[j] == 'U' :
                    ny, nx = y - 1, x
                else :
                    ny, nx = y + 1, x
                
                if ny < 0 or ny >= n or nx < 0 or nx >= n :
                    break
                
                y, x = ny, nx
                ret[i] += 1
        
        return ret
