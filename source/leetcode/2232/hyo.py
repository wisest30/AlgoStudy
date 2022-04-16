class Solution:
    def minimizeResult(self, expression: str) -> str:
        def get_num(l, r) :
            if l == r : return 1
            else : return int(expression[l:r])

        n = len(expression)
        pi = expression.find("+")
        
        ret, min_val = "", float("inf")
        for i in range(pi) :
            for j in range(pi + 1, n) :
                val = get_num(0, i) * (get_num(i, pi) + get_num(pi + 1, j + 1)) * get_num(j + 1, n)
                if val < min_val :
                    ret = expression[:i] + "(" + expression[i:j + 1] + ")" + expression[j + 1:]
                    min_val = val
        
        return ret
