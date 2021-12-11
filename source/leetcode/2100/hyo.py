class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        left, right = [0] * n, [0] * n
        for i in range(1, n) :
            left[i] = left[i-1] + 1 if security[i-1] >= security[i] else 0
        for i in range(n-2, -1, -1) :
            right[i] = right[i+1] + 1 if security[i] <= security[i+1] else 0
        
        return [i for i in range(n) if min(left[i], right[i]) >= time]
