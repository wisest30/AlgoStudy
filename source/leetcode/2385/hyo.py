class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        MAX_N = 10 ** 5 + 10
        sys.setrecursionlimit(MAX_N)
        g = [[] for _ in range(MAX_N)]
        def treenode_dfs(cur) :
            if not cur : return
            for child in [cur.left, cur.right] :
                if child :
                    g[cur.val].append(child.val)
                    g[child.val].append(cur.val)
                    treenode_dfs(child)
        
        treenode_dfs(root)
        
        def dfs(cur, prev) :
            ret = 0
            for nxt in g[cur] :
                if nxt != prev :
                    ret = max(ret, dfs(nxt, cur) + 1)
            
            return ret
        
        return dfs(start, -1)
        
