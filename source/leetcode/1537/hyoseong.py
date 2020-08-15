class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        ret = s1 = s2 = 0
        n1, n2 = len(nums1), len(nums2)
        nums1.append(9999999999999999)
        nums2.append(9999999999999999)
        i = j = 0
        while i < n1 or j < n2 :
            if nums1[i] < nums2[j] :
                s1 += nums1[i]
                i += 1
            elif nums1[i] > nums2[j] :
                s2 += nums2[j]
                j += 1
            else :
                ret += max(s1, s2) + nums1[i]
                s1 = s2 = 0
                i += 1
                j += 1
        
        ret += max(s1, s2)
        return ret % 1000000007
