class Solution:
    def countPoints(self, rings: str) -> int:
        A = [0] * 10
        for i in range(0, len(rings), 2) :
            color = rings[i]
            digit = rings[i+1]
            A[int(digit)] |= 1 << "RGB".index(color)
        
        return A.count(0b111)
        
