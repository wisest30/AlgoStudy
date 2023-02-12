#include <stdio.h>
 
int N, M;
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d %d", &N, &M);
 
		int A1, A2, A3, A4;
 
		int rSum;
		int cSum;
 
		int r1, r2, c1, c2;
 
		int temp;
 
		printf("SCAN 1 1\n");
		fflush(stdout);
 
		scanf("%d", &A1);
 
		printf("SCAN 1 %d\n", M);
		fflush(stdout);
 
		scanf("%d", &A2);
 
		rSum = (A1 + A2 + 6 - 2 * M) / 2;
		cSum = (A1 - A2 + 2 + 2 * M) / 2;
 
		printf("SCAN %d 1\n", rSum / 2);
		fflush(stdout);
 
		scanf("%d", &A3);
		
		r1 = (A1 - A3 + 2) / 2;
		r2 = rSum - r1;
 
		printf("SCAN 1 %d\n", cSum / 2);
		fflush(stdout);
 
		scanf("%d", &A4);
 
		c1 = (A1 - A4 + 2) / 2;
		c2 = cSum - c1;
 
		printf("DIG %d %d\n", r1, c1);
		fflush(stdout);
 
		scanf("%d", &temp);
 
		if (temp == 1)
		{
			printf("DIG %d %d\n", r2, c2);
			fflush(stdout);
 
			scanf("%d", &temp);
		}
		else
		{
			printf("DIG %d %d\n", r1, c2);
			fflush(stdout);
 
			scanf("%d", &temp);
 
			printf("DIG %d %d\n", r2, c1);
			fflush(stdout);
 
			scanf("%d", &temp);
		}
	}
 
	return 0;
}
