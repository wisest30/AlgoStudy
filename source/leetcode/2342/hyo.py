class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        D, ret = dict(), -1
        for num in nums :
            key = sum(map(int, str(num)))
            if key in D :
                ret = max(ret, num + D[key])
                D[key] = max(D[key], num)
            else :
                D[key] = num
        
        return ret
