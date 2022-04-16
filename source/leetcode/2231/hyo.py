class Solution:
    def largestInteger(self, num: int) -> int:
        def even_digit(d) :
            return (ord(d) - ord('0')) % 2 == 0
    
        odd = sorted([d for d in str(num) if not even_digit(d)])
        even = sorted([d for d in str(num) if even_digit(d)])
        ret = []
        for d in str(num) :
            if even_digit(d) :
                ret.append(even.pop())
            else :
                ret.append(odd.pop())
        
        return int("".join(ret))
        
