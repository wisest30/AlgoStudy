from collections import defaultdict

class Solution:
    def findCenter(self, edges) -> int:
        def def_value():
            return 0

        count = defaultdict(def_value)
        for edge in edges:
            count[edge[0]] += 1
            count[edge[1]] += 1

            if count[edge[0]] == 2:
                return edge[0]
            elif count[edge[1]] == 2:
                return edge[1]


if __name__ == "__main__":
    solution = Solution()

    assert(solution.findCenter([[1,2],[2,3],[4,2]]) == 2)
    assert(solution.findCenter([[1,2],[5,1],[1,3],[1,4]]) == 1)
    assert(solution.findCenter([[1,3],[2,3]]) == 3)
