class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key = lambda x : x[0]-x[1])
        
        t0, t1 = zip(*tasks)
        ret = s = 0
        
        for t in tasks :
            ret = max(ret, s + t[1])
            s += t[0]

        return ret
