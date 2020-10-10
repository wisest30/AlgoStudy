class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        p = len(requests)
        ret = 0
        for subset in range(1 << p) :
            A = [0] * n
            cnt = 0
            for i in range(p) :
                r = requests[i]
                if subset & (1 << i) :
                    cnt += 1
                    A[r[0]] -= 1
                    A[r[1]] += 1
            
            for a in A :
                if a != 0 :
                    break
            else :
                ret = max(ret, cnt)
        
        return ret
