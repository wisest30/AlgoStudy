class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        def f(n) :
            return sum(int(c) for c in str(n))
        
        mul = 1
        ret = 0
        while f(n) > target :
            if n % 10 :
                ret += mul * (10 - n % 10)
                n += 10 - n % 10
            
            n //= 10
            mul *= 10
        
        return ret
                