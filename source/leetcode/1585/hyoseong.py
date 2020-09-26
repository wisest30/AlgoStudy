class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        if sorted(s) != sorted(t) : return False
        A = list(map(int, s))
        B = list(map(int, t))
        
        n = len(A)
        left = [0] * 10
        right = [0] * 10
        for a in A :
            right[a] += 1
        
        D = [deque() for _ in range(10)]
        for a in A :
            right[a] -= 1
            
            min_idx = sum(left[:a+1])
            max_idx = n - 1 - sum(right[a:])
            D[a].append([min_idx, max_idx])
            
            left[a] += 1
        
        for i, d in enumerate(B) :
            if D[d][0][0] <= i <= D[d][0][1] :
                D[d].popleft()
            else :
                return False

        return True
