#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll TCC;
ll totalN;


int sol2(int NN, int first) {
	if (NN == 2)return 1;
	if (NN < 2)return 0;

	int i = 2;
	if (first == 1)i = 3;
	int ret = 1;
	for (; i <= NN/2; i++) {
		if(NN%i==0)
			ret = max(ret, sol2(NN / i - 1 ,0) +1 );
	}
	return ret;
}



void sol() {
	
	
	int NN;
	cin >> NN;
	int ret = sol2(NN,1);
	cout << ret << endl;
}
int main() {

	cin >> TCC;
//	make_prime();

	for (int i = 0; i < TCC; i++) {
		cout << "Case #" << i + 1 << ": ";
		sol();
	}
}
