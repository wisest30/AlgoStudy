class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        def get_kth(k) :
            d = (intLength + 1) // 2
            if k > 10 ** d - 10 ** (d - 1) :
                return -1

            left_num = 10 ** (d - 1) + k - 1
            left = str(left_num)
            right = left[::-1] if intLength % 2 == 0 else left[:-1][::-1]
            return left + right
                
        return [get_kth(q) for q in queries]
