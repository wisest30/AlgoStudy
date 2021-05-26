#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int arr[100001];
ll KP[50022];
int L, K;
const ll MOD = 1e9 + 7;
ll ret = 0;
ll retminus = 0;
void sol() {

	cin >> L >> K;
	KP[0] = 1;
	for (int i = 1; i < L / 2 + 5; i++) {
		KP[i] = (KP[i - 1] * K) % MOD;
	}
	for (int i = 0; i < L; i++) {
		char t;
		cin >> t;
		int in = t - 'a'+1;
		arr[i] = in;
	}
	if (L == 1) {
		ret = arr[0] - 1;
	}
	else {
		ret = 0;
		retminus = 1;
		int mid = (L - 1) / 2;
		for (int i = 0; i <= mid; i++) {
			ret = (ret + (arr[i] - 1)*KP[mid - i]) % MOD;
		}
		ret++;

		for (int i = mid + 1; i < L; i++) {
			int left = L - 1 - i;
			if (arr[left] > arr[i]) {
				ret--;
				break;
			}
			else if (arr[left] < arr[i]) {
				break;
			}
			if (i == L - 1)ret--;
		}
		ret %= MOD;
	}
	
	cout << ret << endl;

	
	

}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		sol();
	}

}
