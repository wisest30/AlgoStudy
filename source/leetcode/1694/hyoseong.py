class Solution:
    def reformatNumber(self, number: str) -> str:
        number = number.replace(" ", "").replace("-", "")
        i = 0
        A = []
        while i < len(number) :
            remain = len(number) - i
            if remain < 4 :
                A.append(number[i:])
                i += remain
            elif remain == 4 :
                A.append(number[i:i+2])
                A.append(number[i+2:i+4])
                i += 4
            else :
                A.append(number[i:i+3])
                i += 3
        
        ret = "-".join(A)
        return ret
