class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        v, h = destination
        n = v + h
        
        skip = k - 1        
        ret = []
        for i in range(n) :
            if v == 0 :
                ret.append('H')
                h -= 1
            elif h == 0 :
                ret.append('V')
                v -= 1
            else :
                p = math.comb(v + h - 1, v)
                if skip >= p :
                    ret.append('V')
                    v -= 1
                    skip -= p
                else :
                    ret.append('H')
                    h -= 1
        
        return "".join(ret)
