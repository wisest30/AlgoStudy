class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        char_set = set(s)
        max_len = -1
        for char in char_set:
            first_idx = -1
            last_idx = -1
            for idx, cur_char in enumerate(s):
                if cur_char == char:
                    if first_idx == -1:
                        first_idx = idx
                    else:
                        last_idx = idx
            if first_idx != -1 and last_idx != -1:
                max_len = max(max_len, last_idx - first_idx - 1)
        return max_len