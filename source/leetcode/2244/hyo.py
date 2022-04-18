class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        c = Counter(tasks)
        ret = 0
        for cnt in c.values() :
            if cnt == 1 :
                return -1
            if cnt % 3 == 0 :
                ret += cnt // 3
            else :
                ret += cnt // 3 + 1
        
        return ret
