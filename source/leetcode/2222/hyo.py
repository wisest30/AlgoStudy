class Solution:
    def numberOfWays(self, s: str) -> int:
        right_cnts = Counter(s)
        left_cnts = Counter()
        
        ret = 0
        for c in s :
            right_cnts[c] -= 1
            if c == '0' : ret += left_cnts['1'] * right_cnts['1']
            else : ret += left_cnts['0'] * right_cnts['0']
            left_cnts[c] += 1
        
        return ret
