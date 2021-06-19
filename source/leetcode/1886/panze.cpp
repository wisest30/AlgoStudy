#define ull unsigned long long
#define uint unsigned int

class Solution {
public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    const uint size = mat.size();

    uint i = 0;
    uint j = 0;
    for (; i < size; ++i) {
      for (; j < size; ++j) {
        if (mat[i][j] != target[i][j]) goto next;
      }
    }
    return true;

    next:
    for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
        if (mat[i][j] != target[j][size - i - 1]) goto next2;
      }
    }
    return true;

    next2:
    for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
        if (mat[i][j] != target[size - i - 1][size - j - 1]) goto next3;
      }
    }
    return true;

    next3:
    for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
        if (mat[i][j] != target[size - j - 1][i]) goto next4;
      }
    }
    return true;

    next4:
    return false;
  }
};
