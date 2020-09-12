class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        n = len(nums)
        ret = 0
        pos_p = []
        pos_m = []
        for i in range(n) :
            if nums[i] == 0 :
                pos_p = []
                pos_m = []
            elif nums[i] > 0 :
                pos_p.append(i)
            else :
                pos_m.append(i)
            
            if len(pos_m) % 2 == 0 :
                ret = max(ret, len(pos_p) + len(pos_m))
            else :
                if not pos_p :
                    ret = max(ret, len(pos_m) - 1)
                else :
                    candi1 = max(pos_p[-1], pos_m[-1]) - pos_m[0]
                    candi2 = pos_m[-1] - min(pos_p[0], pos_m[0])
                    ret = max([ret, candi1, candi2])
        return ret
