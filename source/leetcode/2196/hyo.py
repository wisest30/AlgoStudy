class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        d = dict()
        for par, child, isLeft in descriptions :
            d.setdefault(child, TreeNode(child))
            if isLeft :
                d.setdefault(par, TreeNode(par)).left = d[child]
            else :
                d.setdefault(par, TreeNode(par)).right = d[child]
        
        return d[(set(d.keys()) - set(dec[1] for dec in descriptions)).pop()]
