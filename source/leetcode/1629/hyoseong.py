class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        ret = [releaseTimes[0], keysPressed[0]]
        for i in range(1, len(releaseTimes)) :
            ret = max(ret, [releaseTimes[i] - releaseTimes[i-1], keysPressed[i]])
        return ret[1]
