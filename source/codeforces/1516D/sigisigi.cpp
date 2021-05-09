#include <bits/stdc++.h>

using namespace std;

int prime_init[100001];
int prime_num[20000];
int prime_N;
int arr[100000];
vector<vector<int>> arr_prime_list;
vector<vector<int>> prime_seperate;
map<int, int>cnt;
int dp1[100000][20];
int N, Q;
void make_prime() {
	prime_seperate.resize(100001);
	for (int i = 2; i < 100001; i++) {
		prime_init[i] = 1;
	}
	for (int i = 2; i < 100001;i++) {
		if (prime_init[i] == 0)continue;
		int n = i;
		prime_seperate[i].push_back(n);
		for (int j = n * 2; j < 100001; j += n) {
			if (prime_init[j])prime_init[j] = 0;
			prime_seperate[j].push_back(n);
		}
		prime_num[prime_N++]=n;
	}
	for (int i = 0; i < prime_N;i++) {
		cnt[prime_num[i]] = 0;
	}
}

void cnt_minus(int st) {
	for (int z = 0; z < arr_prime_list[st].size(); z++) {
		cnt[arr_prime_list[st][z]]--;
	}
}
void make_dp1() {
	int st = 0;
	for (int i = 0; i < N; i++) {
		for (int z = 0; z < arr_prime_list[i].size(); z++) {
			while (cnt[arr_prime_list[i][z]] > 0) {
				cnt_minus(st);
				dp1[st][0] = i-1;
				st++;
			}
			cnt[arr_prime_list[i][z]]++;
		}
	}
	while(st<N)dp1[st++][0] = N-1;

}
void make_bin_shift() {
	for (int i = 1; i < 20; i++) {
		for (int k = 0; k < N; k++) {
			if (dp1[k][i - 1] >= N - 1)dp1[k][i] = INT_MAX;
			else dp1[k][i] = dp1[dp1[k][i - 1]+1][i - 1];
		}
	}
}
	
void query(int L, int R) {
	int ans = 0;
	int i = 20;
	while (i--) {
		if (dp1[L][i] <= R ) {
			ans += (1 << i);
			L = dp1[L][i]+1;
		}
		if (L > R) {
			break;
		}
	}
	if (L <= R)ans++;
	cout << ans << endl;
}
int main() {
	cin >> N >> Q;
	make_prime();
	arr_prime_list.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int n : prime_seperate[arr[i]])
			arr_prime_list[i].push_back(n);
	}
	make_dp1();
	make_bin_shift();
	for (int q = 0; q < Q; q++) {
		int L, R;
		cin >> L >> R;
		query(L-1, R-1);
	}

	
}
