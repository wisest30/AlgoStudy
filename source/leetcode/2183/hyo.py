class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        divs = [i for i in range(1, k+1) if k % i == 0]
        counter, ret = Counter(), 0
        for num in nums :
            ret += counter[k // math.gcd(num, k)]
            for div in divs :
                if num % div == 0 :
                    counter[div] += 1
        
        return ret
