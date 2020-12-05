class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        alpha_num = {}
        for idx, a in enumerate(alphabet, 1):
          alpha_num[idx] = a

        max_val = len(alphabet) - 1
        non_a_count = math.ceil((k - n) / max_val)
        result = []

        for i in range(n - non_a_count):
          result.append(alpha_num[1])
          k -= 1
        for i in range(non_a_count):
          appended_value = 0
          if k in alpha_num: # 있으면 그냥 넣는다.
            appended_value = k
            result.append(alpha_num[k])
          else:
            appended_value = len(alphabet)
            result.append(alpha_num[len(alphabet)])
          k -= appended_value

        return "".join(sorted(result))
