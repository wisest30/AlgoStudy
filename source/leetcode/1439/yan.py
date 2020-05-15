class Solution:
    def kthSmallestPairs(self, nums1, nums2, k):
        heap = []
        def push(i, j):
            if i < len(nums1) and j < len(nums2):
                heappush(heap, (nums1[i] + nums2[j], i, j))

        push(0, 0)
        pairs = []
        while heap and k:
            _, i, j = heappop(heap)
            pairs.append((nums1[i] + nums2[j]))
            push(i, j + 1)
            if j == 0:
                push(i + 1, 0)
            k -= 1
        return pairs


    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        res = mat[0]
        for nums in mat[1:]:
            res = self.kthSmallestPairs(res, nums, k)
        return res[-1]
