class Solution {
public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    bool valid[3] = { false, false, false };

    for (const auto& triplet : triplets) {
      if (triplet[0] == target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) valid[0] = true;
      if (triplet[0] <= target[0] && triplet[1] == target[1] && triplet[2] <= target[2]) valid[1] = true;
      if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] == target[2]) valid[2] = true;
    }

    return valid[0] & valid[1] & valid[2];
  }
};