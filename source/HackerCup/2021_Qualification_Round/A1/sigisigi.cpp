#include <bits/stdc++.h>
#define Local 

using namespace std;
int tc;
int isV[256] = { 0, };
#ifdef Local
ifstream inputfile;
ofstream outputfile;
#endif
int solve() {
	string input;
#ifdef Local
	inputfile >> input;
#else
	cin >> input;
#endif
	int ret = 987654321;
	for (int i = 0; i < input.size();i++) {
		int sum = 0;
		char target = input[i];
		for (int j = 0; j < input.size();j++) {
			if (i == j)continue;
			if (target == input[j])continue;
			if (isV[target] == isV[input[j]])sum += 2;
			else sum++;
		}
		ret = min(ret, sum);
	}
	int Vcnt=0;
	int Ccnt=0;
	for (int i = 0; i < input.size(); i++) {
		if (isV[input[i]])Vcnt++;
		else Ccnt++;
	}
	if(Vcnt==input.size()|| Ccnt == input.size())
		ret = min(ret, (int)input.size());
	return ret;


}
int main() {
	isV['A'] = 1;
	isV['E'] = 1;
	isV['I'] = 1;
	isV['O'] = 1;
	isV['U'] = 1;
#ifdef Local
	inputfile.open("./consistency_chapter_1_input.txt");
	outputfile.open("./output.txt");
	inputfile >> tc;
#else
	cin >> tc;
#endif
	for (int i = 1; i <= tc; i++) {
#ifdef Local
		outputfile << "Case #" << i << ": " << solve() << endl;
#else
		cout << "Case #" << i << ": " << solve() << endl;
#endif
	}
}
