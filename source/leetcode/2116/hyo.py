class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        def check_forward(s, locked, reverse = False) :
            if len(s) % 2 :
                return False

            p = c = 0
            for i in range(len(s)) :
                if locked[i] == '0' :
                    c += 1
                else :
                    if (s[i] == '(' and not reverse) or (s[i] == ')' and reverse):
                        p += 1
                    else :
                        p -= 1
                
                if p < 0 and c > 0 :
                    p += 1
                    c -= 1
                
                if p < 0 :
                    return False

            return True
        
        return check_forward(s, locked) and check_forward(s[::-1], locked[::-1], True)
