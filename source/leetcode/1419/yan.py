class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        n = 0
        
        count = {c: 0 for c in 'croak'}
        for c in croakOfFrogs:
            if c not in count:
                return -1
            
            count[c] += 1
            if any(count[x] < count[c] for x in 'croak'[:'croak'.index(c)]):
                return -1
            
            if all(count[c] >= 1 for c in count):
                for c in count:
                    count[c] -= 1
            
            n = max([n] + list(count.values()))
        
        return n if all(count[c] == 0 for c in count) else -1
