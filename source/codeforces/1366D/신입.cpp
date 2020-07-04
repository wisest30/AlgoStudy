#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
const ll border = 1e7;
bool isNotPrime[5000];
vector<int> oddPrimes;
int arr[500000 + 5][2];
 
int main()
{
 
	for (int i = 2; 1LL * i * i <= border; i++)
	{
		if (!isNotPrime[i])
		{
			for (ll j = 1LL * i * i; j*j <= border; j += i)
			{
				isNotPrime[j] = true;
			}
			if (i & 1) oddPrimes.push_back(i);
		}
	}
 
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		int input;
		scanf("%d", &input);
 
		arr[i][0] = arr[i][1] = -1;
 
		if (input % 2 == 0)
		{
			int temp = 1;
			while (input % 2 == 0)
			{
				input /= 2;
				temp *= 2;
			}
			if (input != 1)
			{
				arr[i][0] = temp;
				arr[i][1] = input;
			}
		}
		else
		{
			int targetIdx = 0;
 
			for (int oddPrime : oddPrimes)
			{
				if (input < oddPrime) break;
				if (input % oddPrime == 0)
				{
					while (input % oddPrime == 0) input /= oddPrime;
					arr[i][targetIdx++] = oddPrime;
					if (targetIdx == 2) break;
				}
			}
 
			if (targetIdx < 2)
			{
				if (input != 1 && arr[i][0] != -1) arr[i][1] = input;
				else arr[i][0] = arr[i][1] = -1;
			}
		}
	}
 
	for (int i = 0; i < N; i++) printf("%d ", arr[i][0]);
	printf("\n");
	for (int i = 0; i < N; i++) printf("%d ", arr[i][1]);
	printf("\n");
 
	return 0;
}
