class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        leading_num = {piece[0]: piece for piece in pieces}
        i = 0
        n = len(arr)
        candidate = []
        while i < n:
            if arr[i] in leading_num:
                candidate.append(leading_num[i])
            i += 1
        return arr == [x for inner_list in candidate for x in inner_list]

