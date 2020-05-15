import string
from itertools import islice


def solve():
  s = input()
  n = int(input())

  alphabets = len(string.ascii_lowercase)
  count = [[0] * alphabets for _ in range(len(s) + 1)]

  for i, c in enumerate(s, 1):
      count[i] = count[i - 1][:]
      count[i][ord(c) - ord('a')] += 1

  def query(l, r):
      if l == r:
          return 'Yes'
      if s[l - 1] != s[r - 1]:
          return 'Yes'

      unique = (True for x, y in zip(count[l - 1], count[r]) if y - x > 0)
      if len(list(islice(unique, 3))) == 3:
          return 'Yes'

      return 'No'

  for _ in range(n):
      print(query(*map(int, input().split())))


solve()
