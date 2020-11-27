class OrderedStream:
    def __init__(self, n: int):
        self.arr = [None]*(n + 1)
        self.ptr = 1
        self.n = n

    def insert(self, id: int, value: str) -> List[str]:
        self.arr[id] = value
        ret = []
        while self.ptr <= self.n and self.arr[self.ptr]:
            ret.append(self.arr[self.ptr])
            self.ptr += 1
        return ret
