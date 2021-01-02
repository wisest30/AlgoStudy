#include <iostream>
#include <vector>
using namespace std;
void solve() {
	int n;
	cin >> n;
	int a, b;
	a = n / 2 + 1;
	b = (n + 1) / 2 + 1;
	int ans = a * b;
	if (a != b) ans *= 2;
	cout << ans << endl;
}
int main() {
	solve();
}
