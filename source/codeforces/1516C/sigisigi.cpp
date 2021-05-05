#include <bits/stdc++.h>

using namespace std;

int dp[101][200501];
int arr[101];
int L;
void recursive(int idx, int val) {
	if (idx == L)return;
	if (dp[idx][val])return;
	dp[idx][val] = 1;
	recursive(idx+1, val + arr[idx]);
	recursive(idx + 1, val);
}

int main() {
	
	cin >> L;
	
	int sum = 0;
	for (int i = 0; i < L; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum % 2) {
		printf("0\n");
		return 0;
	}
	int target = sum / 2;
	/// 100*2000=200,000;

	recursive(0, 0);


	if (dp[L - 1][target]==0) {
		printf("0\n");
		return 0;
	}
	while (1) {
		for (int i = 0; i < L; i++) {
			if (arr[i] % 2) {
				printf("1\n");
				printf("%d\n", i + 1);
				return 0;
			}
			arr[i] /= 2;
		}
	}


}
