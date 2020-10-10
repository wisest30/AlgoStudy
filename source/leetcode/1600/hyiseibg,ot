class MyNode :
    def __init__(self, name) :
        self.name = name
        self.child = []
    def addChild(self, node) :
        self.child.append(node)

class ThroneInheritance:

    def __init__(self, kingName: str):
        self.D = set()
        self.root = MyNode(kingName)
        self.map = dict()
        self.map[kingName] = self.root

    def birth(self, parentName: str, childName: str) -> None:
        new_node = MyNode(childName)
        self.map[parentName].addChild(new_node)
        self.map[childName] = new_node

    def death(self, name: str) -> None:
        self.D.add(name)

    def getInheritanceOrder(self) -> List[str]:
        ret = []
        
        stack_ = [self.root]
        while stack_ :
            cur = stack_.pop()
            if cur.name not in self.D :
                ret.append(cur.name)
            for i in range(len(cur.child) - 1, -1, -1) :
                stack_.append(cur.child[i])

        return ret
# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
