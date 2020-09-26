class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        if sorted(s) != sorted(t) : return False
        A = list(map(int, s))
        B = list(map(int, t))
        
        n = len(A)
        left = collections.Counter(A)
        right = collections.Counter()
        
        D = [[] for _ in range(10)]
        for i in range(n-1, -1, -1) :
            left[A[i]] -= 1
            
            cnt = 0
            for d in range(A[i]+1) :
                cnt += left[d]
            left_idx = cnt
            
            cnt = 0
            for d in range(A[i], 10) :
                cnt += right[d]
            right_idx = n - 1 - cnt
            
            D[A[i]].append([left_idx, right_idx])
            
            right[A[i]] += 1
        
        for i in range(n) :
            if D[B[i]][-1][0] <= i <= D[B[i]][-1][1] :
                D[B[i]].pop()
            else :
                return False

        return True
        
