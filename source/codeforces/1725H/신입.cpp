#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
 
int input[1'00000 + 5];
char output[1'00000 + 5];
int cnt[3];
int zeroCnt;
 
int main()
{
	int N;
 
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
		cnt[input[i] % 3]++;
		if (input[i] % 3 == 0 && zeroCnt < N / 2)
		{
			zeroCnt++;
			output[i] = '0';
		}
	}
 
	for (int i = 0; i < N; i++)
	{
		if (output[i]) continue;
 
		if (zeroCnt < N / 2)
		{
			zeroCnt++;
			output[i] = '0';
		}
		else output[i] = '1';
	}
	
	if (cnt[0] >= N / 2) printf("2\n%s\n", output);
	else printf("0\n%s\n", output);
 
	return 0;
}
