class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        C, ret = Counter(nums), [0, 0]
        for c in C.values() :
            ret[0] += c // 2
            ret[1] += c % 2
        
        return ret
