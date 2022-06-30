class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        g = [[] for _ in range(n)]
        
        for e in edges :
            g[e[0]].append(e[1])
            g[e[1]].append(e[0])
        
        time, st, et, vals = 0, [0] * n, [0] * n, [0] * n
        def dfs(cur, prev) :
            nonlocal time
            
            st[cur] = time
            time += 1
            
            vals[cur] = nums[cur]
            for nxt in g[cur] :
                if nxt != prev :
                    dfs(nxt, cur)
                    vals[cur] ^= vals[nxt]
            
            et[cur] = time
            time += 1
        
        dfs(0, -1)
        
        ret = float('inf')
        for i in range(1, n) :
            for j in range(i + 1, n) :
                a = b = c = 0
                if st[i] < st[j] < et[j] < et[i] :
                    a, b, c = vals[0] ^ vals[i], vals[i] ^ vals[j], vals[j]
                elif st[j] < st[i] < et[i] < et[j] :
                    a, b, c = vals[0] ^ vals[j], vals[j] ^ vals[i], vals[i]
                else :
                    a, b, c = vals[0] ^ vals[i] ^ vals[j], vals[i], vals[j]
        
                ret = min(ret, max(a, b, c) - min(a, b, c))
        
        return ret
                    
        
        
