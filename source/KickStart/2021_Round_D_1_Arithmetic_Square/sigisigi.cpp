#include <bits/stdc++.h>

using namespace std;

int grid[3][3];
int set_map[8][3][2] = {
	{ { 0,0 },{ 0,1 },{ 0,2 } },
	{ { 2,0 },{ 2,1 },{ 2,2 } },
	{ { 0,0 },{ 1,0 },{ 2,0 } },
	{ { 0,2 },{ 1,2 },{ 2,2 } },


	{ { 0,1 },{ 1,1 },{ 2,1 } },
	{ { 1,0 },{ 1,1 },{ 1,2 } },
	{ { 0,0 },{ 1,1 },{ 2,2 } },
	{ { 2,0 },{ 1,1 },{ 0,2 } },
};

bool isprog(int map[3][2]) {
	int a = grid[map[0][0]][map[0][1]];
	int b = grid[map[2][0]][map[2][1]];
	int mid = grid[map[1][0]][map[1][1]];
	if (a + b == mid * 2)return true;
	return false;
}
int get_middle(int map[3][2]) {
	int a = grid[map[0][0]][map[0][1]];
	int b = grid[map[2][0]][map[2][1]];
	int mid = (a + b) / 2;
	if (a + b == mid * 2)return mid;
	return -1023456789;
}
void sol() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 1 && i == 1) {
				grid[i][j] = -1;
			}
			else
				cin >> grid[i][j];
		}
	}
	int ret = 0;


	for (int i = 4; i < 8; i++) {
		int temp_ret = 0;
		int temp = get_middle(set_map[i]);
		if (temp == -1023456789)continue;
		grid[1][1] = temp;
		for (int j = 4; j < 8; j++) {
			if (isprog(set_map[j]))temp_ret++;
		}
		ret = max(ret, temp_ret);
	}
	for (int i = 0; i < 4; i++) {
		if (isprog(set_map[i]))ret++;
	}
	cout << ret;



}

int main() {
	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cout << "Case #" << i << ": ";
		sol();
		cout << endl;
	}


}
