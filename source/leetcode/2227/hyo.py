class Encrypter:

    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.e = dict(zip(keys, values))
        self.counter = Counter([self.encrypt(s) for s in dictionary])

    def encrypt(self, word1: str) -> str:
        return "".join([self.e[c] if c in self.e else '_' for c in word1])

    def decrypt(self, word2: str) -> int:
        return self.counter[word2] if word2 in self.counter else 0


# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)
