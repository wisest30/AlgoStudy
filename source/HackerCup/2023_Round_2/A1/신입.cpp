#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include <algorithm>

using namespace std;

int R, C;

char input[3'000 + 5][3'000 + 5];
bool visit[3'000 + 5][3'000 + 5];
int score[3'000 + 5][3'000 + 5];

int emptyR;
int emptyC;
bool valid;

int whiteCnt;

constexpr int dr[4] = { 0, 1, 0, -1 };
constexpr int dc[4] = { 1, 0, -1, 0 };

void dfs(int r, int c)
{
	if (input[r][c] == '.')
	{
		if (emptyR == -1) emptyR = r, emptyC = c;
		else if(emptyR != r || emptyC != c) valid = false;
		return;
	}

	visit[r][c] = true;
	whiteCnt++;

	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i], nc = c + dc[i];

		if (nr >= R || nr < 0 || nc >= C || nc < 0) continue;
		if (input[nr][nc] == 'B') continue;
		if (visit[nr][nc]) continue;
		dfs(nr, nc);
	}
}

void solve()
{
	memset(visit, 0, sizeof(visit));
	memset(score, 0, sizeof(score));

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) scanf("%s", input[i]);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (input[i][j] == 'W' && !visit[i][j])
			{
				emptyR = -1;
				valid = true;
				whiteCnt = 0;
				dfs(i, j);

				if (valid && emptyR != -1) score[emptyR][emptyC] += whiteCnt;
				
			}
		}
	}

	int mx = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++) mx = max(mx, score[i][j]);
	}

	if (mx) printf("YES\n");
	else printf("NO\n");

	// printf("%d\n", mx);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d: ", tc);
		solve();
	}

	return 0;
}
