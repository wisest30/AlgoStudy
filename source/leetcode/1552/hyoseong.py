class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        def check(mm) :
            last = 0
            cnt = 1
            for  i in range(1, len(position)) :
                if position[i] - position[last] >= mm :
                    last = i
                    cnt += 1
            return cnt >= m
        
        l, r = 0, 10 ** 10
        while l + 1 < r :
            mm = (l + r) // 2
            if check(mm) :
                l = mm
            else :
                r = mm
        return l
