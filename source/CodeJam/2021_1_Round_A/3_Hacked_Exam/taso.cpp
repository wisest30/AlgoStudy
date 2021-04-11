#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(vector<char>& arr);
int N, Q;
vector<string> qs;
vector<int> scores;
int answerCnt;
vector<int> tCnt;

int gcd(int p, int q) {
  if (q==0)
    return p;
  return gcd(q, p%q);
}

void solve(int problemIdx) {
  vector<char> tmp;
  dfs(tmp);
  string sol;
  int numer = 0;
  for (int i=0; i<tCnt.size(); i++) {
    if (tCnt[i]*2 < answerCnt) {
      numer += answerCnt - tCnt[i];
      sol += 'F';
    } else {
      numer += tCnt[i];
      sol += 'T';
    }
  }
  int g = gcd(answerCnt, numer);
  int denom = answerCnt/g;
  numer = numer/g;
  cout << "Case #" << (problemIdx+1) << ": " << sol << " " << numer << "/" << denom << endl;
}

void dfs(vector<char>& arr) {
  if (arr.size() == Q) {
    for (int i=0; i<N; i++) {
      int sameCnt = 0;
      for (int j=0; j<Q; j++) {
        if (qs[i][j] == arr[j])
          sameCnt++;
      }
      if (sameCnt != scores[i])
        return;
    }
    answerCnt++;
    for (int i=0; i<arr.size(); i++)
      tCnt[i] += arr[i] == 'T';
    return;
  }
  arr.push_back('T');
  dfs(arr);
  arr.pop_back();
  arr.push_back('F');
  dfs(arr);
  arr.pop_back();
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N >> Q;
    qs.resize(N);
    scores.resize(N);
    tCnt = vector<int>(Q, 0);
    answerCnt = 0;
    for (int j=0; j<N; j++)
      cin >> qs[j] >> scores[j];
    solve(i);
  }
}