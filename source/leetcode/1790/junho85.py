class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True

        if len(s1) != len(s2):
            return False

        first = None
        second = None
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                if first is None:
                    first = (s1[i], s2[i])
                elif second is None:
                    second = (s1[i], s2[i])
                else:
                    return False

        if first is None or second is None:
            return False

        if first[0] == second[1] and first[1] == second[0]:
            return True
        else:
            return False


if __name__ == "__main__":
    solution = Solution()

    assert(solution.areAlmostEqual("bank", "kanb") == True)
    assert(solution.areAlmostEqual("attack", "defend") == False)
    assert(solution.areAlmostEqual("kelb", "kelb") == True)
    assert(solution.areAlmostEqual("abcd", "dcba") == False)
    assert(solution.areAlmostEqual("aa", "ac") == False)
