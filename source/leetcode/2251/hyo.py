class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], persons: List[int]) -> List[int]:
        persons = [[persons[i], i] for i in range(len(persons))]
        flowers.sort()
        persons.sort()
        q, ret = [], [0] * len(persons)
        i = j = 0
        while j < len(persons) :
            if i < len(flowers) and flowers[i][0] <= persons[j][0] :
                heappush(q, flowers[i][1])
                i += 1
            else :
                while q and q[0] < persons[j][0] :
                    heappop(q)
                ret[persons[j][1]] = len(q)
                j += 1
        
        return ret
            
