#include <stdio.h>
 
using namespace std;
 
constexpr size_t MAXN = 2'00000 + 5;
 
int N;
int input[MAXN];
int output[MAXN];
bool isZero[MAXN];
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d", &N);
 
		for (int i = 0; i < N; i++) isZero[i] = false;
 
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &input[i]);
 
			if (input[i] == 0) output[i] = 0;
			else
			{
				if (isZero[i]) output[i] = 0;
				else output[i] = 1;
 
				int nextZero = input[i] - i * (1 - isZero[i]);
				
				if (i + nextZero < N) isZero[i + nextZero] = true;
			}
		}
 
		for (int i = 0; i < N; i++) printf("%d ", output[i]);
		printf("\n");
	}
 
	return 0;
}
