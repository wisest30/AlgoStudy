#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> cellsInRange(string s) {
    vector<string> ret;
    
    for (char c = s[0]; c <= s[3]; c++) {
      for (char r = s[1]; r <= s[4]; r++) {
        string tmp;
        tmp += c;
        tmp += r;
        ret.push_back(tmp);
      }
    }
    return ret;
  }
};