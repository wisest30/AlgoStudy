class Solution:
    def add_on_same_parity_index(self, s, add_amount, parity):
        digit_list = [int(char) for char in s]
        changed_string = ''
        for idx, digit in enumerate(digit_list):
            if idx % 2 == parity:
                changed_string += str((digit + add_amount) % 10)
            else: changed_string += str(digit)
        return changed_string

    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        n = len(s)
        a_set = set([a*i for i in range(10)])
        b_set = set([b*i%n for i in range(n)])
        odd_string_set = set()
        even_string_set = set()
        candidate_strings = set()
        for add_amount in a_set:
            odd_string_set.add(self.add_on_same_parity_index(s, add_amount, 1))
            if b % 2: even_string_set.add(self.add_on_same_parity_index(s, add_amount, 0))
        if b % 2 == 0: even_string_set.add(s)
        for even_string in even_string_set:
            for odd_string in odd_string_set:
                candidate_string = ''
                for idx in range(n):
                    if idx % 2 == 0: candidate_string += even_string[idx]
                    else: candidate_string += odd_string[idx]
                candidate_strings.add(candidate_string)
        min_string = s
        for candidate_string in candidate_strings:
            for rotate in b_set:
                min_string = min(min_string, candidate_string[-rotate:] + candidate_string[:-rotate])
        return min_string
