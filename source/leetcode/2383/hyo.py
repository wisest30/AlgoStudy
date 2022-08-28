class Solution:
    def minNumberOfHours(self, a: int, b: int, energy: List[int], experience: List[int]) -> int:
        ret = 0
        for i in range(len(energy)) :
            ret += max(energy[i] + 1 - a, 0) + max(experience[i] + 1 - b, 0)
            a, b = max(a, energy[i] + 1) - energy[i], max(b, experience[i] + 1) + experience[i]
        
        return ret
            
