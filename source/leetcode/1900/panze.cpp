#define ull unsigned long long
#define uint unsigned int
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define FOR(I,N) for(int I = 0; I < N; ++I)

class Solution {
 public:
   Solution() 
     : min_mem(28, vvi(28, vi(28, -1))),
       max_mem(28, vvi(28, vi(28, -1))) {}

  vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    int left = firstPlayer - 1, mid = secondPlayer - 1 - firstPlayer, right = n - secondPlayer;

    cout << "left: " << left << ", mid: " << mid << ", right: " << right << endl;

    vi ret;
    ret.push_back(min_dp(left, mid, right));
    ret.push_back(max_dp(left, mid, right));

    return ret;
  }

 private:
  int min_dp(int left, int mid, int right) {
    if (left == right) return 1;
    if (left + mid + right <= 2) return 2;

    int& ret = min_mem[left][mid][right];
    if (ret != -1) return ret;
    ret = 10000;

    if (left > right) {
      left--;
      if (left > right + mid) left--;
      else if (left < right + mid) mid--;
    } else {
      right--;
      if (right > left + mid) right--;
      else if (right < left + mid) mid--;
    }

    const int repeat = (left + mid + right) / 2;
    const bool odd = (left + mid + right) & 0x01;
    int odd_add[3] = { 0, 0, 0 };

    int half_pos;
    int l[3] = {0, 0, 0};
    int r[3] = {0, 0, 0};

    for (int i = 0; i < repeat; ++i) {
      if (left > 0) {
        l[0]++;
        left--;
      } else if (mid > 0) {
        l[1]++;
        mid--;
      } else {
        l[2]++;
        right--;
      }
    }

    if (left > 0) {
      half_pos = 0;
      if (odd) {
        left--;
        odd_add[0] = 1;
      }
    } else if (mid > 0) {
      half_pos = 1;
      if (odd) {
        mid--;
        odd_add[1] = 1;
      }
    } else {
      half_pos = 2;
      if (odd) {
        right--;
        odd_add[2] = 1;
      }
    }

    for (int i = 0; i < repeat; ++i) {
      if (left > 0) {
        r[0]++;
        left--;
      } else if (mid > 0) {
        r[1]++;
        mid--;
      } else {
        r[2]++;
        right--;
      }
    }

    if (half_pos == 0) {
      int next_left = l[0];
      int next_mid = r[1];
      int next_right = r[2];

      for (int i = 0; i <= r[1]; ++i) {
        for (int j = 0; j <= r[2]; ++j) {
          ret = min(ret, 1 + min_dp(next_left - (r[1] - i) - (r[2] - j) + odd_add[0], next_mid - i + odd_add[1], next_right - j + odd_add[2]));
        }
      }
    } else if (half_pos == 1) {
      int next_left = l[0];
      int next_mid = max(l[1], r[1]);
      int next_right = r[2];

      if (l[1] <= r[1]) {
        int rest_r1 = r[1] - l[1];

        for (int i = 0; i <= rest_r1; ++i) {
          for (int j = 0; j <= r[2]; ++j) {
            ret = min(ret, 1 + min_dp(next_left - (rest_r1 - i) - (r[2] - j) + odd_add[0], next_mid - i + odd_add[1], next_right - j + odd_add[2]));
          }
        }
      } else {
        int rest_l1 = l[1] - r[1];

        for (int i = 0; i <= l[0]; ++i) {
          for (int j = 0; j <= rest_l1; ++j) {
            ret = min(ret, 1 + min_dp(next_left - i + odd_add[0], next_mid - j + odd_add[1], next_right - (l[0] - i) - (rest_l1 - j) + odd_add[2]));
          }
        }
      }

    } else if (half_pos == 2) {
      int next_left = l[0];
      int next_mid = l[1];
      int next_right = r[2];

      for (int i = 0; i <= l[0]; ++i) {
        for (int j = 0; j <= l[1]; ++j) {
          ret = min(ret, 1 + min_dp(next_left - i + odd_add[0], next_mid - j + odd_add[1], next_right - (l[0] - i) - (l[1] - j) + odd_add[2]));
        }
      }
    }

    return ret;
  }

  int max_dp(int left, int mid, int right) {
    if (left == right) return 1;
    if (left + mid + right <= 1) return 2;

    int& ret = max_mem[left][mid][right];

    if (ret != -1) return ret;
    ret = 0;

    if (left > right) {
      left--;
      if (left > right + mid) left--;
      else if (left < right + mid) mid--;
    } else {
      right--;
      if (right > left + mid) right--;
      else if (right < left + mid) mid--;
    }

    const int repeat = (left + mid + right) / 2;
    const bool odd = (left + mid + right) & 0x01;
    int odd_add[3] = { 0, 0, 0 };

    int half_pos;
    int l[3] = { 0, 0, 0 };
    int r[3] = { 0, 0, 0 };

    for (int i = 0; i < repeat; ++i) {
      if (left > 0) {
        l[0]++;
        left--;
      } else if (mid > 0) {
        l[1]++;
        mid--;
      } else {
        l[2]++;
        right--;
      }
    }

    if (left > 0) {
      half_pos = 0;
      if (odd) {
        left--;
        odd_add[0] = 1;
      }
    } else if (mid > 0) {
      half_pos = 1;
      if (odd) {
        mid--;
        odd_add[1] = 1;
      }
    } else {
      half_pos = 2;
      if (odd) {
        right--;
        odd_add[2] = 1;
      }
    }

    for (int i = 0; i < repeat; ++i) {
      if (left > 0) {
        r[0]++;
        left--;
      } else if (mid > 0) {
        r[1]++;
        mid--;
      } else {
        r[2]++;
        right--;
      }
    }

    if (half_pos == 0) {
      int next_left = l[0];
      int next_mid = r[1];
      int next_right = r[2];

      for (int i = 0; i <= r[1]; ++i) {
        for (int j = 0; j <= r[2]; ++j) {
          ret = max(ret, 1 + max_dp(next_left - (r[1] - i) - (r[2] - j) + odd_add[0], next_mid - i + odd_add[1], next_right - j + odd_add[2]));
        }
      }
    } else if (half_pos == 1) {
      int next_left = l[0];
      int next_mid = max(l[1], r[1]);
      int next_right = r[2];

      if (l[1] <= r[1]) {
        int rest_r1 = r[1] - l[1];

        for (int i = 0; i <= rest_r1; ++i) {
          for (int j = 0; j <= r[2]; ++j) {
            ret = max(ret, 1 + max_dp(next_left - (rest_r1 - i) - (r[2] - j) + odd_add[0], next_mid - i + odd_add[1], next_right - j + odd_add[2]));
          }
        }
      } else {
        int rest_l1 = l[1] - r[1];

        for (int i = 0; i <= l[0]; ++i) {
          for (int j = 0; j <= rest_l1; ++j) {
            ret = max(ret, 1 + max_dp(next_left - i + odd_add[0], next_mid - j + odd_add[1], next_right - (l[0] - i) - (rest_l1 - j) + odd_add[2]));
          }
        }
      }

    } else if (half_pos == 2) {
      int next_left = l[0];
      int next_mid = l[1];
      int next_right = r[2];

      for (int i = 0; i <= l[0]; ++i) {
        for (int j = 0; j <= l[1]; ++j) {
          ret = max(ret, 1 + max_dp(next_left - i + odd_add[0], next_mid - j + odd_add[1], next_right - (l[0] - i) - (l[1] - j) + odd_add[2]));
        }
      }
    }

    return ret;
  }

  vvvi min_mem;
  vvvi max_mem;
};
