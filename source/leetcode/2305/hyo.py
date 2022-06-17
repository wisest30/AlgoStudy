class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        n, ret = len(cookies), float('inf')
        for subset in range(k ** (n-1)) :
            A = [cookies[0]] + [0] * (n - 1)
            for i in range(1, n) :
                A[subset % k] += cookies[i]
                subset //= k
            ret = min(ret, max(A))
        
        return ret
