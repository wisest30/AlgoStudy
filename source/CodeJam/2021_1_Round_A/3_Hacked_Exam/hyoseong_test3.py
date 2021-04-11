from collections import deque as dq
from collections import defaultdict as dd
from collections import Counter as ct
from functools import lru_cache as lc
from heapq import heappush as hpush, heappop as hpop, heapify as hfy
from bisect import bisect_left, bisect_right
import itertools as it
import math
import sys
import threading
sys.setrecursionlimit(10**5)
threading.stack_size(1 << 27)
input=sys.stdin.readline
####################################################################

def nCr(n, r) :
	return math.factorial(n) // math.factorial(r) // math.factorial(n-r)

class Solution :
	def solve(self) :
		comb = nCr
		gcd = math.gcd

		n, q = map(int, input().split())
		
		A = []
		for _ in range(n) :
			x = input().split()
			A.append([x[0], int(x[1])])

		while len(A) < 3 :
			A.append(A[0][:])

		T00 = T01 = T10 = T11 = 0
		tp = []
		for i in range(q) :
			c0 = A[0][0][i]
			c1 = A[1][0][i]
			c2 = A[2][0][i]

			if c0 != c1 and c0 != c2 :
				T00 += 1
				tp.append(0)
			elif c0 != c1 and c0 == c2 :
				T01 += 1
				tp.append(1)
			elif c0 == c1 and c0 != c2 :
				T10 += 1
				tp.append(2)
			else :
				T11 += 1
				tp.append(3)
		
		total = 0
		c00 = c01 = c10 = c11 = 0
		for t00 in range(T00 + 1) :
			for t01 in range(T01 + 1) :
				for t10 in range(T10 + 1) :
					t11 = A[0][1] - t00 - t01 - t10

					if t11 < 0 or t11 > T11 : continue
					if T00 - t00 + T01 - t01 + t10 + t11 != A[1][1] : continue
					if T00 - t00 + t01 + T10 - t10 + t11 != A[2][1] : continue

					total += comb(T00, t00) * comb(T01, t01) * comb(T10, t10) * comb(T11, t11)

					if t00 > 0 : c00 += comb(T00 - 1, t00 - 1) * comb(T01, t01) * comb(T10, t10) * comb(T11, t11)
					if t01 > 0 : c01 += comb(T00, t00) * comb(T01-1, t01-1) * comb(T10, t10) * comb(T11, t11)
					if t10 > 0 : c10 += comb(T00, t00) * comb(T01, t01) * comb(T10-1, t10-1) * comb(T11, t11)
					if t11 > 0 : c11 += comb(T00, t00) * comb(T01, t01) * comb(T10, t10) * comb(T11-1, t11-1)

		ret0 = []
		ret1 = 0
		ret2 = total
		for i in range(q) :
			c = A[0][0][i]
			r = 'T' if c == 'F' else 'F'

			if tp[i] == 0 :
				if c00 * 2 >= total :
					ret0.append(c)
					ret1 += c00
				else :
					ret0.append(r)
					ret1 += total - c00
			elif tp[i] == 1 :
				if c01 * 2 >= total :
					ret0.append(c)
					ret1 += c01
				else :
					ret0.append(r)
					ret1 += total - c01
			elif tp[i] == 2 :
				if c10 * 2 >= total :
					ret0.append(c)
					ret1 += c10
				else :
					ret0.append(r)
					ret1 += total - c10
			elif tp[i] == 3 :
				if c11 * 2 >= total :
					ret0.append(c)
					ret1 += c11
				else :
					ret0.append(r)
					ret1 += total - c11
		
		ret0 = "".join(ret0)

		if ret1 == 0 :
			ret2 = 1
		else :
			g = gcd(ret1, ret2)
			ret1 //= g
			ret2 //= g

		print(ret0, str(ret1) + "/" + str(ret2))




def main() :
	t = int(input())
	#t = 1
	for i in range(t) :
		print("Case #" + str(i+1) + ": ", end = "")
		s = Solution()
		s.solve()

thread = threading.Thread(target=main)
thread.start()
thread.join()
