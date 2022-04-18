class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        n = len(parent)
        g = [[] for _ in range(n)]
        for i in range(1, n) :
            g[parent[i]].append(i)
        
        def dfs(cur) :
            ret0 = ret1 = 1
            sub_rets = []
            for nxt in g[cur] :
                sub_ret0, sub_ret1 = dfs(nxt)
                ret0 = max(ret0, sub_ret0)
                if s[nxt] != s[cur] :
                    sub_rets.append(sub_ret1)
                    ret1 = max(ret1, 1 + sub_ret1)
            
            sub_rets.sort()
            if len(sub_rets) >= 2 :
                ret0 = max(ret0, 1 + sub_rets[-1] + sub_rets[-2])
            elif len(sub_rets) == 1 :
                ret0 = max(ret0, 1 + sub_rets[-1])
        
            return [ret0, ret1]
        
        return dfs(0)[0]
