class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key = lambda x : x[0]-x[1])
        
        ret = s = 0
        for task in tasks :
            ret = max(ret, s + task[1])
            s += task[0]

        return ret
