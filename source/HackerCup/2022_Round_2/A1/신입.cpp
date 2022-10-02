#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

constexpr int SZ = 1'000000 + 5;

char input[SZ];
int sum[SZ][26]{};

void solve()
{
	vector<int> alphabets[26];

	scanf("%s", input + 1);

	for (int i = 1; input[i]; i++)
	{
		for (int j = 0; j < 26; j++) sum[i][j] = sum[i - 1][j];
		alphabets[input[i] - 'a'].push_back(i);
		sum[i][input[i] - 'a']++;
	}

	int ans = 0;
	int Q;

	scanf("%d", &Q);

	for (int i = 0; i < Q; i++)
	{
		int L, R;

		scanf("%d %d", &L, &R);

		if ((R - L) % 2 == 0)
		{
			char oddAlphabet = 0;
			bool oddValid = true;

			int target[26]{};

			for (int j = 0; j < 26; j++)
			{
				target[j] = sum[R][j] - sum[L - 1][j];
				if (target[j] % 2)
				{
					if (oddAlphabet)
					{
						oddValid = false;
						break;
					}
					else oddAlphabet = j + 'a';
				}
			}

			if (!oddValid) continue;

			int mid = (L + R) / 2;

			if (input[mid] == oddAlphabet)
			{
				int left[26]{};
				int right[26]{};
				bool valid = true;

				for (int j = 0; j < 26; j++)
				{
					left[j] = sum[mid - 1][j] - sum[L - 1][j];
					right[j] = sum[R][j] - sum[mid][j];

					if (left[j] != right[j])
					{
						valid = false;
						break;
					}
				}

				if (valid)
				{
					ans++;
					continue;
				}
			}

			char targetAlphabet = oddAlphabet - 'a';
			auto leftIdx = lower_bound(alphabets[targetAlphabet].begin(), alphabets[targetAlphabet].end(), L);

			if (*leftIdx <= mid - 1)
			{
				int left[26]{};
				int right[26]{};
				bool valid = true;

				for (int j = 0; j < 26; j++)
				{
					left[j] = sum[mid][j] - sum[L - 1][j];
					right[j] = sum[R][j] - sum[mid][j];

					if (j == oddAlphabet - 'a') left[j]--;

					if (left[j] != right[j])
					{
						valid = false;
						break;
					}
				}

				if (valid)
				{
					ans++;
					continue;
				}
			}

			auto rightIdx = lower_bound(alphabets[targetAlphabet].begin(), alphabets[targetAlphabet].end(), mid+1);

			if (*rightIdx <= R)
			{
				int left[26]{};
				int right[26]{};
				bool valid = true;

				for (int j = 0; j < 26; j++)
				{
					left[j] = sum[mid-1][j] - sum[L - 1][j];
					right[j] = sum[R][j] - sum[mid-1][j];

					if (j == oddAlphabet - 'a') right[j]--;

					if (left[j] != right[j])
					{
						valid = false;
						break;
					}
				}

				if (valid)
				{
					ans++;
					continue;
				}
			}
		}
	}

	printf("%d\n", ans);
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
