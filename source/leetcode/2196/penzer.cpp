#include <bits/stdc++.h>

using namespace std;

TreeNode node[100001];

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
      set<int> parents;
      set<int> childs;

      memset(node, 0, sizeof(node));

      for (auto &description : descriptions) {
        if (description[2]) node[description[0]].left = &node[description[1]];
        else node[description[0]].right = &node[description[1]];

        node[description[0]].val = description[0];
        node[description[1]].val = description[1];

        parents.insert(description[0]);
        childs.insert(description[1]);
      }

      for (auto &child : childs) {
        parents.erase(child);
      }

      int root = 0;
      for (auto &parent : parents) {
        root = parent;
      }

      return &node[root];
    }
};