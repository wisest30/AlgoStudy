class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        index = []
        for i in range(len(nums)):
            for j in range(len(nums[i])):
                if len(index) <= i + j:
                    index.append([])
                index[i + j].append(nums[i][j])
       
        return [x for i in index for x in reversed(i)]
