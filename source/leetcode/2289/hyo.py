class Solution:
    def totalSteps(self, nums: List[int]) -> int:
        ret, st = 0, []
        for num in nums:
            if not st or num >= st[0][0]:
                st = [[num, 0]]
            else :
                max_step = 0
                while st[-1][0] <= num :
                    max_step = max(max_step, st.pop()[1])
                st.append([num, max_step + 1])
                ret = max(ret, max_step + 1)
        
        return ret
                
