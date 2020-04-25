class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        result = []
        heading = [set(range(m)) for m in range(m)]
        for query in queries:
            result.append(len(heading[query - 1]))
            for h in heading[query - 1]:
                heading[h].add(query - 1)
            heading[query - 1] = set()
        
        return result
