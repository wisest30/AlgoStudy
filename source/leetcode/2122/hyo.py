class Solution:
    def recoverArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        
        K = set()
        for num in nums[1:] :
            if num > nums[0] and num % 2 == nums[0] % 2:
                K.add((num - nums[0]) // 2)

        for k in K :
            C = Counter(nums)
            keys = sorted(C.keys())
            ret = []
            for key in keys :
                while C[key] > 0 :
                    if not C[key + 2 * k] :
                        break
                    C[key] -= 1
                    C[key + 2 * k] -= 1
                    ret.append(key + k)
                else :
                    continue
                break
            else :
                return ret
        
        return []
