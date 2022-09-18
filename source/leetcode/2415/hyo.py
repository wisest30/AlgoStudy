class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        A = []
        def dfs(cur, depth) :
            if not cur : return
            if depth % 2 :
                i = (depth - 1) // 2
                if i == len(A) : A.append([])
                A[i].append(cur)
                
            dfs(cur.left, depth + 1)
            dfs(cur.right, depth + 1)
            
        dfs(root, 0)
        for nodes in A :
            n = len(nodes)
            for i in range(n // 2) :
                nodes[i].val, nodes[n - 1 - i].val = nodes[n - 1 - i].val, nodes[i].val
        
        return root