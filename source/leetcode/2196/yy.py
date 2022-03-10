# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
      
        result={}
        child_list={}
        for each in descriptions:
            p,c,is_left=each
            if p not in result:
                result[p]=TreeNode(p)
            if c not in result:
                result[c]=TreeNode(c)
            if is_left : 
                result[p].left = result[c]
            else:
                result[p].right = result[c]
            child_list[c]=""
        for each in descriptions:
            if each[0] not in child_list: head=each[0]
        return result[head]
        
