class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        g = defaultdict(list)
        start_path, dest_path = [], []
        def dfs(cur, path, d) :
            nonlocal start_path, dest_path
            
            path.append([cur.val, d])
            if cur.val == startValue :
                start_path = copy.deepcopy(path)
            if cur.val == destValue :
                dest_path = copy.deepcopy(path)
            
            if cur.left :
                dfs(cur.left, path, 'L')
            if cur.right :
                dfs(cur.right, path, 'R')
            path.pop()
        
        dfs(root, [], "")
        
        i, n, m = 0, len(start_path), len(dest_path)
        while i < min(n, m) and start_path[i][0] == dest_path[i][0] :
            i += 1
        
        ret = ['U'] * (n - i)
        while i < m :
            ret.append(dest_path[i][1])
            i += 1

        return "".join(ret)
        
