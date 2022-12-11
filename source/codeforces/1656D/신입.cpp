#include <stdio.h>

typedef long long ll;

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		ll evenPart = 1;
		ll oddPart = 1;

		ll N;

		scanf("%lld", &N);

		if (N % 2) printf("2\n");
		else
		{
			while (N % 2 == 0)
			{
				N /= 2;
				evenPart *= 2;
			}

			oddPart = N;

			ll target = oddPart - 2 * evenPart + 1;
			
			if (target > 0 && target % 2 == 0)
			{
				printf("%lld\n", 2 * evenPart);
				continue;
			}

			target = evenPart - (oddPart + 1) / 2 + 1;

			if (target > 0)
			{
				if (oddPart == 1) printf("-1\n");
				else printf("%lld\n", oddPart);
				continue;
			}

			printf("-1\n");
		}
	}

	return 0;
}
