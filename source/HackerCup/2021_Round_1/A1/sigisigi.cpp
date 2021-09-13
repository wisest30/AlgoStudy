#include <bits/stdc++.h>
#define INPUTXX
#define A2
using namespace std;
int tc;
int N;
int solve() {
	cin >> N;
	string input;
	cin >> input;
	int leftHand = 0;
	int switchCnt = 0;
	for (char c : input){
		if (c == 'X') {
			if (leftHand == -1) switchCnt++;
			leftHand = 1;
		}
		else if (c == 'O') {
			if (leftHand == 1) switchCnt++;
			leftHand = -1;
		}
	}
	return switchCnt;

}

int main() {
#ifdef INPUT
	freopen("output.txt", "w", stdout);
	freopen("weak_typing_chapter_1_input.txt", "r", stdin);
#endif
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << ": ";
		cout << solve();
		cout << endl;
	}
}
