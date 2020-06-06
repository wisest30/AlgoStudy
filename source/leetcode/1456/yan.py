class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        res = 0

        start, count = 0, 0
        vowels = set("aeiou")
        for end in range(len(s)):
            count += s[end] in vowels
            if end - start + 1 > k:
                count -= s[start] in vowels
                start += 1
            if end - start + 1 == k:
                res = max(res, count)

        return res
