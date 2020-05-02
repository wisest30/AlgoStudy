class Solution:
    def reformat(self, s: str) -> str:
        digit_str = "0123456789"
        digits = [c for c in s if c in digit_str]
        letters = [c for c in s if c not in digit_str]

        digits_cnt = len(digits)
        letters_cnt = len(letters)
        
        if abs(digits_cnt - letters_cnt) > 1 :
            return ""
        
        ret = []
        if digits_cnt > letters_cnt :
            ret.append(digits.pop())
        elif letters_cnt > digits_cnt :
            ret.append(letters.pop())
        
        while digits or letters :
            if ret and ret[-1] in digit_str :
                ret.append(letters.pop())
            else :
                ret.append(digits.pop())
        
        return "".join(ret)
