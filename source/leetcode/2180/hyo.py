class Solution:
    def countEven(self, num: int) -> int:
        return len(list(filter(lambda x : x % 2 == 0, [sum(map(int, str(i))) for i in range(1, num+1)])))
        
