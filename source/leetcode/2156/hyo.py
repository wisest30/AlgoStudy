class Solution:
    def subStrHash(self, s: str, power: int, modulo: int, k: int, hashValue: int) -> str:
        val = lambda x : ord(x) - ord('a') + 1
        n = len(s)
        s = list(reversed(s))
        start_idx = 0
        h, p = functools.reduce( \
                lambda acc, x : [(acc[0] * power + val(x)) % modulo, acc[1] * power % modulo], \
                s[:k],
                [0, 1])

        for i in range(k, n) :
            h = (h * power - val(s[i-k]) * p + val(s[i])) % modulo
            if h == hashValue : start_idx = i - k + 1

        return "".join(reversed(s[start_idx:start_idx + k]))
