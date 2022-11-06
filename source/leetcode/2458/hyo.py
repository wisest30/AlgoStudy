# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        A, cnts, D = [], [], []
        def dfs(cur, depth) :
            if not cur :
                return 0
            ret = 1
            ret += dfs(cur.left, depth + 1)
            ret += dfs(cur.right, depth + 1)
            A.append(cur.val)
            cnts.append(ret)
            D.append(depth)
            
            return ret
        
        dfs(root, 0)
        
        n = len(A)
        left_max, right_max = D[::], D[::]
        for i in range(1, n) :
            left_max[i] = max(left_max[i], left_max[i-1])
        for i in range(n-2, -1, -1) :
            right_max[i] = max(right_max[i], right_max[i+1])
        
        m = dict()
        for i in range(n) :
            m[A[i]] = i

        ret = []
        for q in queries :
            i = m[q]
            right = i + 1
            left = right - cnts[i]
            x = max(0 if left == 0 else left_max[left - 1], 0 if right == n else right_max[right])
            ret.append(x)
        
        return ret
            