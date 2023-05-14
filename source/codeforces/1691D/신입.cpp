#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;
constexpr size_t MAXN = 2'00000 + 5;
constexpr ll INF = 4'000'000'000'000'000;
constexpr ll MINUS_INF = -INF;

ll prefixMxTree[4 * MAXN];
ll suffixMxTree[4 * MAXN];

ll arr[MAXN];
ll prefixSum[MAXN];
ll suffixSum[MAXN];

int rightBorder[MAXN];
int leftBorder[MAXN];

void init(ll* tree, int node, int s, int e)
{
	if (s == e)
	{
		tree[node] = MINUS_INF;
		return;
	}

	init(tree, node * 2, s, (s + e) / 2);
	init(tree, node * 2 + 1, (s + e) / 2 + 1, e);
}

void update(ll* tree, int node, int s, int e, int idx, ll diff)
{
	if (s > idx || e < idx) return;

	if (s == e)
	{
		tree[node] = diff;
		return;
	}

	update(tree, node * 2, s, (s + e) / 2, idx, diff);
	update(tree, node * 2 + 1, (s + e) / 2 + 1, e, idx, diff);

	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

ll getMx(ll* tree, int node, int s, int e, int l, int r)
{
	if (s >= l && e <= r) return tree[node];
	if (e < l || s > r) return MINUS_INF;

	return max(getMx(tree, node * 2, s, (s + e) / 2, l, r), getMx(tree, node * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main()
{
	int T;

	scanf("%d", &T);

	prefixSum[0] = 0LL;
	arr[0] = INF;

	while (T--)
	{
		int N;

		scanf("%d", &N);

		stack<int> idxStack;

		init(prefixMxTree, 1, 1, N);
		init(suffixMxTree, 1, 1, N);

		arr[N + 1] = INF;
		suffixSum[N + 1] = 0LL;

		for (int i = 1; i <= N+1; i++)
		{
			if (i <= N) scanf("%lld", &arr[i]);
			
			while (!idxStack.empty() && arr[idxStack.top()] < arr[i])
			{
				int topIdx = idxStack.top();
				rightBorder[topIdx] = i - 1;
				idxStack.pop();
			}

			idxStack.push(i);

			prefixSum[i] = prefixSum[i - 1] + arr[i];

			if(i <= N) update(prefixMxTree, 1, 1, N, i, prefixSum[i]);
		}

		idxStack.pop();

		for (int i = N; i >= 0; --i)
		{
			while (!idxStack.empty() && arr[idxStack.top()] < arr[i])
			{
				int topIdx = idxStack.top();
				leftBorder[topIdx] = i + 1;
				idxStack.pop();
			}

			idxStack.push(i);

			suffixSum[i] = suffixSum[i + 1] + arr[i];

			if (i > 0) update(suffixMxTree, 1, 1, N, i, suffixSum[i]);
		}

		bool YES = true;

		for (int i = 1; i <= N; i++)
		{
			ll rightMxSum = getMx(prefixMxTree, 1, 1, N, i, rightBorder[i]) - prefixSum[i];
			ll leftMxSum = getMx(suffixMxTree, 1, 1, N, leftBorder[i], i) - suffixSum[i];

			if (rightMxSum + leftMxSum > 0)
			{
				YES = false;
				break;
			}
		}

		if (YES) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
