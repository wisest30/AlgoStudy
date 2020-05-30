class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        groups = [i for i in range(len(favoriteCompanies))]
        favoriteCompaniesSet = list(map(set, favoriteCompanies))

        def union(x, y):
            x, y = find(x), find(y)
            if x == y:
                return

            xSet, ySet = favoriteCompaniesSet[x], favoriteCompaniesSet[y]
            if xSet.issubset(ySet):
                groups[x] = y
            elif ySet.issubset(xSet):
                groups[y] = x

        def find(x):
            if x != groups[x]:
                groups[x] = find(groups[x])
            return groups[x]

        n = len(favoriteCompanies)
        for i in range(n):
            for j in range(i + 1, n):
                union(i, j)

        return sorted(set(find(i) for i in range(n)))
