#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
const int INF = 2000 + 5;
const int MINUS_INF = 0;
 
int n, m;
char board[2000+5][2000+5];
 
int vertical_mn[26];
int vertical_mx[26];
int horizontal_mn[26];
int horizontal_mx[26];
 
bool chk(int idx)
{
	if (vertical_mx[idx] == MINUS_INF)
	{
		vertical_mn[idx] = vertical_mn[idx + 1];
		vertical_mx[idx] = vertical_mx[idx + 1];
		horizontal_mn[idx] = horizontal_mn[idx + 1];
		horizontal_mx[idx] = horizontal_mx[idx + 1];
		return true;
	}
 
	if (vertical_mn[idx] != vertical_mx[idx] && horizontal_mn[idx] != horizontal_mx[idx]) return false;
 
	for (int i = vertical_mn[idx]; i <= vertical_mx[idx]; ++i)
	{
		for (int j = horizontal_mn[idx]; j <= horizontal_mx[idx]; ++j)
		{
			if (board[i][j] == 'a' + idx || board[i][j] == 0) board[i][j] = 0;
			else return false;
		}
	}
 
	return true;
}
 
void init()
{
	for (int i = 0; i < 26; ++i)
	{
		vertical_mn[i] = horizontal_mn[i] = INF;
		vertical_mx[i] = horizontal_mx[i] = MINUS_INF;
	}
}
 
int main()
{
	int t;
 
	scanf("%d", &t);
 
	while (t--)
	{
		init();
 
		scanf("%d %d", &n, &m);
		
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", board[i] + 1);
 
			for (int j = 1; j <= m; ++j)
			{
				if (board[i][j] != '.')
				{
					int idx = board[i][j] - 'a';
 
					vertical_mn[idx] = min(vertical_mn[idx], i);
					vertical_mx[idx] = max(vertical_mx[idx], i);
					horizontal_mn[idx] = min(horizontal_mn[idx], j);
					horizontal_mx[idx] = max(horizontal_mx[idx], j);
				}
			}
		}
 
		bool start = false;
		bool valid = true;
		int last_idx = -1;
 
		for (int i = 25; i >= 0; --i)
		{
			if (!start && vertical_mx[i] != MINUS_INF)
			{
				start = true;
				last_idx = i;
			}
			if (start)
			{
				bool res = chk(i);
				if (!res)
				{
					valid = false;
					break;
				}
			}
		}
 
		if (!valid) printf("NO\n");
		else
		{
			printf("YES\n%d\n", last_idx + 1);
			for (int i = 0; i <= last_idx; ++i) printf("%d %d %d %d\n", vertical_mn[i], horizontal_mn[i], vertical_mx[i], horizontal_mx[i]);
		}
	}
 
	return 0;
}
