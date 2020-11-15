#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[20];
ll pdp[20];

ll boring_nums(int idx, string num){
  int n = num.size();
  if(idx == n) return 1LL;
  ll sum = 0LL;

  ll digit = num[idx] - '0';
  ll digitsCnt = ((idx + 1) & 1) ? (digit + 1)/2 : (digit/2) + 1;
  if(digitsCnt == 0) return 0LL;

  int e = num.size() - idx - 1;
  ll max_digit = ((idx + 1) & 1) ? 2*digitsCnt - 1 : 2*digitsCnt - 2;
  if(max_digit == digit){
    sum += (digitsCnt - 1) * dp[e];
    sum += boring_nums(idx + 1, num);
  }
  else{
    sum += digitsCnt * dp[e];
  }
  
  return sum;
}

void solve(int testNum){
  ll l, r;
  cin >> l >> r;
  string strL = to_string(l - 1), strR = to_string(r);
  int lenL = strL.size(), lenR = strR.size();
  
  ll n1 = boring_nums(0, strL) + pdp[lenL - 1];
  ll n2 = boring_nums(0, strR) + pdp[lenR - 1];
  cout << "Case #" << testNum << ": " << n2 - n1 << "\n";
  return;
}

int main(){
  ll b5 = 1LL;
  for(int i = 0; i< 20; ++i){
      dp[i] = b5;
      if(i > 0) pdp[i] = pdp[i - 1] + b5;
      b5 *= 5LL;
  }

  int T;
  cin >> T;
    for(int t = 1; t<= T; ++t){
      solve(t);
    }
  return 0;
}