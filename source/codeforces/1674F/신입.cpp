#include <stdio.h>

int fenwick[1'000000 + 5];
int n, m;

char board[1'000 + 5][1'000 + 5];
int iconCnt;

void upd(int idx, int diff)
{
	for (; idx <= n * m; idx += (idx&(-idx))) fenwick[idx] += diff;
}

int getSum(int idx)
{
	int ret = 0;
	for (; idx; idx -= (idx&(-idx))) ret += fenwick[idx];
	return ret;
}

int conv(int r, int c)
{
	return (c - 1)*n + r;
}

int main()
{
	int q;
	scanf("%d %d %d", &n, &m, &q);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf(" %c", &board[i][j]);
			if (board[i][j] == '*')
			{
				iconCnt++;
				int idx = conv(i, j);
				upd(idx, 1);
			}
		}
	}

	for (int i = 0; i < q; i++)
	{
		int r, c;

		scanf("%d %d", &r, &c);

		int idx = conv(r, c);

		if (board[r][c] == '.')
		{
			board[r][c] = '*';
			iconCnt++;
			upd(idx, 1);
		}
		else
		{
			board[r][c] = '.';
			iconCnt--;
			upd(idx, -1);
		}

		printf("%d\n", iconCnt - getSum(iconCnt));
	}

	return 0;
}
