class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        for a in sorted(asteroids) :
            if mass < a : return False
            else : mass += a
        return True
        
