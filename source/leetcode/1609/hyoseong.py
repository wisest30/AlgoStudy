# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        A = []
        def dfs(cur, l) :
            if not cur :
                return
            
            if len(A) < l+1 :
                A.append([])

            A[l].append(cur.val)
            dfs(cur.left, l+1)
            dfs(cur.right, l+1)

        dfs(root, 0)        
        for i in range(len(A)) :
            for a in A[i] :
                if i % 2 == a % 2 :
                    return False
            for j in range(len(A[i]) - 1) :
                if i % 2 and A[i][j+1] >= A[i][j]:
                    return False
                if i % 2 == 0 and A[i][j+1] <= A[i][j]:
                    return False
        
        return True
                    
