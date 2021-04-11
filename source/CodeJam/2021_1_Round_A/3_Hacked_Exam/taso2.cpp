#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
long long int dfs(int i, int curS1, int curS2);
// idx, curScore1, curScore2
long long int df[41][41][41];
long long int N, Q, firstTCnt, firstFCnt;
long long int numerMap[2][2];
char solMap[2][2];
vector<string> qs;
vector<int> scores;

void init() {
  memset(df, -1, sizeof(df));
  firstTCnt = 0;
  firstFCnt = 0;
}

long long int gcd(long long int p, long long int q) {
  if (q==0)
    return p;
  return gcd(q, p%q);
}

void solve(int problemIdx) {
  memset(numerMap, -1, sizeof(numerMap));
  memset(solMap, -1, sizeof(solMap));
  string sol;
  long long int numer = 0;
  long long int answerCnt = 0;
  for (int i=0; i<Q; i++) {
    char& solRet = solMap[qs[0][i]=='T'][qs[1][i]=='T'];
    long long int& numerRet = numerMap[qs[0][i]=='T'][qs[1][i]=='T'];
    if (solRet != -1) {
      sol += solRet;
      numer += numerRet;
      continue;
    }
    init();
    swap(qs[0][0], qs[0][i]);
    swap(qs[1][0], qs[1][i]);
    answerCnt = dfs(0, 0, 0);
    if (firstFCnt < firstTCnt) {
      numerRet = firstTCnt;
      solRet = 'T';
    } else {
      numerRet = firstFCnt;
      solRet = 'F';
    }
    numer += numerRet;
    sol += solRet;
  }
  long long int g = gcd(answerCnt, numer);
  long long int denom = answerCnt/g;
  numer = numer/g;
  cout << "Case #" << (problemIdx+1) << ": " << sol << " " << numer << "/" << denom << endl;
}

long long int dfs(int i, int curS1, int curS2) {
  long long int& ret = df[i][curS1][curS2];
  if (ret != -1)
    return ret;
  if (i == Q) {
    ret = curS1 == scores[0] && curS2 == scores[1];
    return ret;
  }
  // if T is true
  long long int a = dfs(i+1, curS1 + (qs[0][i] == 'T'), curS2 + (qs[1][i] == 'T'));
  // if F is true
  long long int b = dfs(i+1, curS1 + (qs[0][i] == 'F'), curS2 + (qs[1][i] == 'F'));
  if (i == 0) {
    firstTCnt = a;
    firstFCnt = b;
  }
  ret = a+b;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T, nTmp;
  N = 2;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> nTmp >> Q;
    qs.resize(N);
    scores.resize(N);
    for (int j=0; j<nTmp; j++)
      cin >> qs[j] >> scores[j];
    for (int i=nTmp; i<N; i++) {
      qs[i] = qs[0];
      scores[i] = scores[0];
    }
    solve(i);
  }
}