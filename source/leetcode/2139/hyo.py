class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        if target == 1 or maxDoubles == 0 : return target - 1
        elif target % 2 == 0 and maxDoubles > 0 : return self.minMoves(target // 2, maxDoubles - 1) + 1;
        else : return self.minMoves(target - 1, maxDoubles) + 1;
