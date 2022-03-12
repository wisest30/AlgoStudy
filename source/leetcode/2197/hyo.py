class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        ret = []
        for num in nums :
            ret.append(num)
            while len(ret) >= 2 and math.gcd(ret[-1], ret[-2]) > 1:
                a, b = ret.pop(), ret.pop()
                ret.append(a * b // math.gcd(a, b))
        
        return ret
