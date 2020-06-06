class Solution:
    def pseudoPalindromicPaths(self, root: TreeNode) -> int:
        def dfs(node, count):
            if not node:
                return 0

            count ^= 1 << (node.val - 1)
            if node.left == node.right:
                return int(count & (count - 1) == 0)

            return dfs(node.left, count) + dfs(node.right, count)

        return dfs(root, 0)
