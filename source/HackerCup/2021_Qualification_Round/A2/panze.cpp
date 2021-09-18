#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int kInf = 32768;

int main(int argc, char** argv) {
  freopen("input.txt", "r", stdin);
  ofstream outfile("output.txt", std::ofstream::binary);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; ++tc) {
    string str;
    cin >> str;

    vector<vector<int>> vvi(256,vector<int>(256, kInf));

    {
      int cnt;
      string tmp;
      cin >> cnt;
      while(cnt--) {
        cin >> tmp;
        vvi[tmp[0]][tmp[1]] = 1;
      }
    }
    
    for (char c = 'A'; c <= 'Z'; ++c) vvi[c][c] = 0;

    for (int i = 'A'; i <= 'Z'; ++i) {
      for (int j = 'A'; j <= 'Z'; ++j) {
        for (int k = 'A'; k <= 'Z'; ++k) {
          vvi[j][k] = min(vvi[j][k], vvi[j][i] + vvi[i][k]);
        }
      }
    }

    int ans = kInf;
    for (char i = 'A'; i <= 'Z'; ++i) {
      int candi = 0;

      for (char c : str) {
        candi += vvi[c][i];
      }

      ans = min(ans, candi);
    }

    outfile << "Case #" << tc << ": " << ((ans < kInf) ? ans : -1) << endl;
    cout << "Case #" << tc << ": " << ((ans < kInf) ? ans : -1) << endl;
  }

  outfile.close();

  return 0;
}