class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        parity = 1
        node_queue = [root]
        while node_queue:
            node_cnt = len(node_queue)
            parity = (parity + 1) % 2
            pre_val = 0 if parity == 0 else 1000001
            while node_cnt > 0:
                node_cnt -= 1
                node = node_queue.pop(0)
                if not node: continue
                if node.val % 2 == parity:
                    return False
                if (parity == 0 and node.val <= pre_val) or (parity == 1 and node.val >= pre_val):
                    return False
                pre_val = node.val
                node_queue.append(node.left)
                node_queue.append(node.right)
        return True