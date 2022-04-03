#include <iostream>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
int gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b % a;  b = c;
	}
	return b;
}

void solve() {
	int r, c; 
	cin >> r >> c;
	string l[2];
	l[0] = "+";
	l[1] = "|";
	for (int i = 0; i < c; i++) {
		l[0] += "-+";
		l[1] += ".|";
	}
	cout << endl;
	l[0][0] = l[0][1] = '.';
	l[1][0] = '.';
	cout << l[0] << endl << l[1] << endl;
	l[0][0] = '+';
	l[0][1] = '-';
	l[1][0] = '|';
	for (int i = 0; i < r; i++) {
		cout << l[0] << endl;
		if (i + 1 < r) {
			cout << l[1] << endl;
		}
	}
	return;
}
int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
