class Solution:
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        def f(nums1, nums2) :
            n = len(nums1)
            A = [nums2[i] - nums1[i] for i in range(n)]
            ps = [0] + list(accumulate(A))
            ret = min_val = 0
            for i in range(1, n+1) :
                ret = max(ret, ps[i] - min_val)
                min_val = min(min_val, ps[i])
            
            ret += sum(nums1)
            
            return ret
        
        return max(f(nums1, nums2), f(nums2, nums1))
