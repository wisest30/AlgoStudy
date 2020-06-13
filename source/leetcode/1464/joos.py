def maxProduct(nums: List[int]) -> int:
    nums.sort()
    return (nums[-1]-1) * (nums[-2]-1)
