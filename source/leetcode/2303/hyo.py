class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        ret = p = 0
        for b in brackets :
            ret += (min(b[0], income) - p) * b[1] / 100
            p = b[0]
            if b[0] >= income :
                break
        
        return ret
