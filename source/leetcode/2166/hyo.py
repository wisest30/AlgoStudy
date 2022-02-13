class Bitset:
    def f(self, idx, val) :
        if self.A[idx] ^ self.flipped != val :
            self.A[idx] ^= True
            self.cnt += 1 if self.A[idx] else -1
            
    def __init__(self, size: int): self.cnt, self.flipped, self.A = 0, False, [False] * size    
    def fix(self, idx: int) -> None: self.f(idx, True)
    def unfix(self, idx: int) -> None: self.f(idx, False)
    def flip(self) -> None: self.flipped ^= True
    def all(self) -> bool: return self.count() == len(self.A)
    def one(self) -> bool: return self.count() > 0
    def count(self) -> int: return self.cnt if not self.flipped else len(self.A) - self.cnt
    def toString(self) -> str: return "".join(map(lambda x : '1' if x ^ self.flipped else '0', self.A))
        


# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()
