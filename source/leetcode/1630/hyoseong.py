class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        ret = []
        for i in range(len(l)) :
            A = sorted(nums[l[i]:r[i] + 1])
            for j in range(len(A) - 1) :
                if A[1] - A[0] != A[j+1] - A[j] :
                    ret.append(False)
                    break
            else :
                ret.append(True)
        return ret
                
