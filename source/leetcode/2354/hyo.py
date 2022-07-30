class Solution:
    def countExcellentPairs(self, nums: List[int], k: int) -> int:
        nums = set(nums)
        d = defaultdict(list)
        for num in nums :
            bit_count = bin(num).count('1')
            d[bit_count].append(num)
        
        ret = 0
        for key0 in d :
            for key1 in d :
                if key0 + key1 >= k :
                    ret += len(d[key0]) * len(d[key1])

        return ret
        
