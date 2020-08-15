class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        if k >= len(arr) : return max(arr)
        arr = arr + arr
        i, j = 0, 1
        win_cnt = 0
        while j < len(arr) :
            if arr[i] > arr[j] :
                win_cnt += 1
                j += 1
            else :
                win_cnt = 1
                i = j
                j += 1
            if win_cnt == k :
                return arr[i]
        return -1 #error
