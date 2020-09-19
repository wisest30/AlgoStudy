class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        S1 = Counter()
        S2 = Counter()
        for i in range(len(nums1)) :
            for j in range(i+1, len(nums1)) :
                S1[nums1[i] * nums1[j]] += 1
        for i in range(len(nums2)) :
            for j in range(i+1, len(nums2)) :
                S2[nums2[i] * nums2[j]] += 1
        
        ret = 0
        for n in nums1 :
            ret += S2[n * n]
        for n in nums2 :
            ret += S1[n * n]
        return ret
