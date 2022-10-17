class Solution:
    def componentValue(self, nums: List[int], edges: List[List[int]]) -> int:
        n, su = len(nums), sum(nums)
        g = [[] for i in range(n)]
        for e in edges :
            g[e[0]].append(e[1])
            g[e[1]].append(e[0])
        
        def dfs(cur, prev, s) :
            ss = nums[cur]
            for nxt in g[cur] :
                if nxt == prev : continue
                sub_ret = dfs(nxt, cur, s)
                if not sub_ret[0] : return (False, 0)
                ss += sub_ret[1]
            
            if ss <= s :
                return (True, ss % s)
            elif ss > s :
                return (False, 0)
                
        for i in range(n-1, 0, -1) :
            cnt = i + 1
            if su % cnt : continue
            if dfs(0, -1, su // cnt)[0] : return i
        
        return 0
