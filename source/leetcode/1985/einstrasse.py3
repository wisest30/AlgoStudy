class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        arr = sorted(map(int, nums), reverse=True)
        return str(arr[k-1])
