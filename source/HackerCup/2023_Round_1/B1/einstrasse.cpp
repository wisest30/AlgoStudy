#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <iomanip>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

#define MAXVAL 5500000
int factor[MAXVAL + 5];
bool is_prime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void preprocess() {
	for (int target = 2; target <= MAXVAL; target++) {
		if (is_prime(target)) {
			int check = target + target;
			while (check <= MAXVAL) {
				if (factor[check] == 0) {
					factor[check] = target;
				}
				check += target;
			}
		}
	}
}
void solve() {
	int n;
	cin >> n;
	int remainder = n;
	if (remainder >= MAXVAL) {
		cout << "-1\n";
		return;
	}
	vector<int> factors;
	while (remainder > 1) {
		
		int fac = factor[remainder];
		if (fac == 0) {
			fac = remainder;
		}
		factors.push_back(fac);
		remainder /= fac;
	}
	int sum = 0;
	for (int item : factors) {
		sum += item;
	}
	if (sum > 41) {
		cout << "-1\n";
	}
	else {
		int counts = factors.size() + 41 - sum;
		cout << counts << ' ';
		for (int item : factors) {
			cout << item << ' ';
		}
		for (int i = sum; i < 41; i++) {
			cout << "1 ";
		}
		cout << endl;
	}
	return;
	
}
int main() {
	freopen("output.txt", "w", stdout);
	preprocess();
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
