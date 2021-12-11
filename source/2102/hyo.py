class SORTracker:
    def __init__(self):
        from sortedcontainers import SortedList
        self.S = SortedList()
        self.i = 0
    def add(self, name: str, score: int) -> None:
        self.S.add((-score, name))
    def get(self) -> str:
        self.i += 1
        return self.S[self.i-1][1]
