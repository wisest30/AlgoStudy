
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        sorted_arr = sorted(collections.Counter(arr).values(), reverse = True)
        while sorted_arr and k>=sorted_arr[-1]: k -= sorted_arr.pop()
        return len(v)
