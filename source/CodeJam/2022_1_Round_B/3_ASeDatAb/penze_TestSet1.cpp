#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Opp {
  int now;
  int cnt;
  
  Opp()
    : now(rand() % 255 + 1), cnt(0) { 
      now = 93;
    }

  int Submit(const string &bits) {
    int r = rand() % 8;
    string rot = "00000000";

    for (int i = 0; i < 8; i++) {
      rot[(i + r) % 8] = bits[i];
    }

    int rot_int = (rot[0] == '1' ? 128 : 0)
                + (rot[1] == '1' ? 64 : 0)
                + (rot[2] == '1' ? 32 : 0)
                + (rot[3] == '1' ? 16 : 0)
                + (rot[4] == '1' ? 8 : 0)
                + (rot[5] == '1' ? 4 : 0)
                + (rot[6] == '1' ? 2 : 0)
                + (rot[7] == '1' ? 1 : 0);

//    cout << "now: " << now << ", rot: " << rot << ", rot_int: " << rot_int << endl;
    now ^= rot_int;
    cnt++;
    if (now == 0) {
    //  cout << "cnt: " << cnt << endl;
      return 0;
    }
    else if (cnt < 300) {
      int ret = 0;
      int tmp = now;
      while (tmp) {
        ret += tmp & 0x01;
        tmp /= 2;
      }
      return ret;
    }

    cout << "failed" << endl;
    return -1;
  }
};

int psuedo_rand() {
  static int seed = 7;
  
  return (seed = (seed * 214013L + 2531011L) >> 16) & 0x7fff;
}

int main () {
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++) {
    Opp opp;

    int cnt = 4;

    while (cnt > 0) {
      string bits = "00000000";
      while (cnt) {
        int r = psuedo_rand() % 8;
        if (bits[r] == '0') {
          cnt--;
          bits[r] = '1';
        }
      }
      
      //cout << "bits: " << bits << ", ";
      cnt = opp.Submit(bits);
      //cout << "cnt: " << cnt << endl;

      // cout << bits << endl;
      // cin >> cnt;
    } 
  }
  return 0;
}


