from heapq import heappush, heappop


class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        s = ''
        
        heap = []
        if a:
            heappush(heap, (-a, 'a'))
        if b:    
            heappush(heap, (-b, 'b'))
        if c:    
            heappush(heap, (-c, 'c'))
        
        while heap:
            n0, c0 = heappop(heap)
            if len(s) >= 2 and s[-1] == s[-2] == c0:
                if heap:
                    n, c = heappop(heap)
                    s += c
                    if n != -1:
                        heappush(heap, (n + 1, c))
                    heappush(heap, (n0, c0))   
                else:     
                    break
            else:         
                s += c0
                if n0 != -1:
                    heappush(heap, (n0 + 1, c0))
                
        return s
