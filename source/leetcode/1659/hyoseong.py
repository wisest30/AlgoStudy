class Solution:
    def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
        def get_type(h, i) :
            return h // (3 ** (i - 1)) % 3
        def set_type(h, i, val) :
            return h - get_type(h, i) + (3 ** (i - 1)) * val
        def add_score(type1, type2) :
            if type1 == 0 or type2 == 0 :
                return 0
            elif type1 == 1 and type2 == 1 :
                return -60
            elif type1 == 2 and type2 == 2 :
                return 40
            else :
                return -10
        
        @lru_cache(None)
        def dp(y, x, intro, extro, h) :
            if y == m :
                return 0
            if x == n :
                return dp(y + 1, 0, intro, extro, h)
            
            upper_type = get_type(h, n) if y > 0 else 0
            left_type = get_type(h, 1) if x > 0 else 0
            next_h = h * 3 % (3 ** n)
            
            ret = dp(y, x + 1, intro, extro, next_h)
            if intro > 0 :
                add = add_score(1, upper_type) + add_score(1, left_type) + 120
                ret = max(ret, dp(y, x + 1, intro - 1, extro, next_h + 1) + add)
            if extro > 0 :
                add = add_score(2, upper_type) + add_score(2, left_type) + 40
                ret = max(ret, dp(y, x + 1, intro, extro - 1, next_h + 2) + add)
            return ret
        
        return dp(0, 0, introvertsCount, extrovertsCount, 0)
                
