class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        MAX_N = 10 ** 5 + 1
        F = [0] * MAX_N
        
        def get(x) :
            ret, i = 0, x
            while i >= 1 :
                ret += F[i]
                i -= i & -i
            return ret
        
        def add(x) :
            i = x
            while i <= MAX_N :
                F[i] += 1
                i += i & -i
        
        ret = 0
        total_cnt = 0
        for a in instructions :
            ret += min(get(a-1), total_cnt - get(a))
            ret %= 10 ** 9 + 7
            total_cnt += 1
            add(a)
        
        return ret
