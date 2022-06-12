class TextEditor:

    def __init__(self):
        self.L, self.R = [], deque()

    def addText(self, text: str) -> None:
        self.L += text

    def deleteText(self, k: int) -> int:
        ret = 0
        while self.L and k :
            self.L.pop()
            k -= 1
            ret += 1
        return ret

    def cursorLeft(self, k: int) -> str:
        while self.L and k :
            self.R.appendleft(self.L.pop())
            k -= 1
        return "".join(self.L[-10:])

    def cursorRight(self, k: int) -> str:
        while self.R and k :
            self.L.append(self.R.popleft())
            k -= 1
        return "".join(self.L[-10:])
