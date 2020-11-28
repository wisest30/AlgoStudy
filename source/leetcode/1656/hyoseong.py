class OrderedStream:

    def __init__(self, n: int):
        self.A = [0] * (n + 1)
        self.p = 0

    def insert(self, id: int, value: str) -> List[str]:
        ret = []
        self.A[id - 1] = value
        while self.A[self.p] != 0 :
            ret.append(self.A[self.p])
            self.p += 1
        return ret
        
        


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(id,value)
