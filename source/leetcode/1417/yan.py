from itertools import zip_longest


class Solution:
    def reformat(self, s: str) -> str:
        digits = [c for c in s if c.isdigit()]
        chars = [c for c in s if not c.isdigit()]
        
        if abs(len(digits) - len(chars)) > 1:
            return ''
        
        a, b = chars, digits
        if len(b) > len(a):
            b, a = a, b
            
        return ''.join((x or '') + (y or '') for x, y in zip_longest(a, b))
