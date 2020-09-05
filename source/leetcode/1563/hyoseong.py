class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        sys.setrecursionlimit(10**8)
        S = [0]
        for val in stoneValue :
            S.append(S[-1] + val)
                   
        @functools.lru_cache(None)
        def recur(l, r) :
            if l >= r :
                return 0
            if l + 1 == r :
                return 0
            
            x = (S[l] + S[r]) / 2
            m = bisect.bisect_left(S, x)
            
            s = max(m - 4, l+1)
            e = min(m + 4, r)
            ret = 0
            for i in range(s, e) :
                left_sum = S[i] - S[l]
                right_sum = S[r] - S[i]
                if left_sum == right_sum :
                    ret = max(ret, left_sum + max(recur(l, i), recur(i, r)))
                elif left_sum < right_sum :
                    ret = max(ret, left_sum + recur(l, i))
                else :
                    ret = max(ret, right_sum + recur(i, r))
            return ret        
        return recur(0, len(stoneValue))
