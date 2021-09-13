#include <bits/stdc++.h>
#define INPUT
#define A2
using namespace std;
int tc;
int M,N;
int A, B;
int solve() {
	cin >> M >> N;
	cin >> A >>B;

	if (A < M + N - 1 || B < M + N - 1) {
		cout << "Impossible" << endl;
		return 0;
	}


	cout << "Possible" << endl;
	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N; j++) {
			cout << "1";
			if (j != N - 1)
				cout << " ";
		}
		cout << endl;
	}
	cout << B - (M - 1) - (N - 1)<<" ";
	for (int j = 1; j < N-1; j++) {
		cout << "1 ";
	}
	cout << A - (M - 1) - (N - 1) ;
	cout << endl;

}

int main() {
#ifdef INPUT
	freopen("output.txt", "w", stdout);
	freopen("traffic_control_input.txt", "r", stdin);
#endif
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

