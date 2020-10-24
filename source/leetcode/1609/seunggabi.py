# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        m = {}

        def go(node, lv):
            if node is None:
                return True

            if lv not in m:
                m[lv] = []
            m[lv].append(node.val)

            if node.val % 2 == (lv + 1) % 2:
                return go(node.left, lv + 1) and \
                       go(node.right, lv + 1)
            return False

        def creasing(m):
            ordering = 1

            for i in range(max(m.keys()) + 1):
                arr = m[i]

                for j in range(len(arr) - 1):
                    t = arr[j + 1] - arr[j]

                    if t == 0 or \
                            t / abs(t) != ordering:
                        return False

                ordering *= -1
            return True

        return go(root, 0) and creasing(m)