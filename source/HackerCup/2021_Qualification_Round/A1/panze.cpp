#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool vowel[256];

int main(int argc, char** argv) {
  freopen("input.txt", "r", stdin);
  ofstream outfile("output.txt", std::ofstream::binary);

  int t;
  cin >> t;

  vowel['A'] = true;
  vowel['E'] = true;
  vowel['I'] = true;
  vowel['O'] = true;
  vowel['U'] = true;

  for (int tc = 1; tc <= t; ++tc) {
    string str;
    cin >> str;

    int ans = 1 << 30;
    for (char i = 'A'; i <= 'Z'; ++i) {
      int candi = 0;

      for (char c : str) {
        if (c == i) continue;
        else candi += (vowel[c] != vowel[i]) ? 1 : 2;
      }

      ans = min(ans, candi);
    }

    outfile << "Case #" << tc << ": " << ans << endl;
  }

  outfile.close();

  return 0;
}