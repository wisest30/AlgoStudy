class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        return sorted(set(list(range(1001))).intersection(*[set(arr) for arr in nums]))
                    
