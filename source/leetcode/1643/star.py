class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        n, m = destination
        answer = ''
        while n and m:
            c = comb(n + m - 1, m - 1)
            if k <= c:
                answer += 'H'
                m-= 1
            else:
                answer += 'V'
                k -= c
                n -=1
        return answer + 'H' * m + 'V' * n
