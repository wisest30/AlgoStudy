class Solution:
    def countTime(self, time: str) -> int:
        ret = 0
        for a in range(10) :
            for b in range(10) :
                for c in range(10) :
                    for d in range(10) :
                        if time[0] != '?' and a != int(time[0]) : continue
                        if time[1] != '?' and b != int(time[1]) : continue
                        if time[3] != '?' and c != int(time[3]) : continue
                        if time[4] != '?' and d != int(time[4]) : continue
                        
                        h = a * 10 + b
                        m = c * 10 + d
                        
                        if h < 24 and m < 60  :
                            ret += 1
        
        return ret
