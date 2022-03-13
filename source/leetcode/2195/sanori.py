class Solution:
  def minimalKSum(self, nums: List[int], k: int) -> int:
    arr = sorted(set(nums))
    res = k * (k + 1) // 2
    upper = k + 1
    for a in arr:
      if (a < upper):
        res += (upper - a)
        upper += 1
    return res
