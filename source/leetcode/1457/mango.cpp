/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10);
        int numPseudoPalindromic = 0;
        if(root != NULL)
            traverse(root, count, numPseudoPalindromic);
        return numPseudoPalindromic;
    }
private:
    void traverse(TreeNode* cur, vector<int>& count, int& numPseudoPalindromic){
        if(cur->left == NULL && cur->right == NULL){
            count[cur->val]++;
            int odd = 0;
            for(int i=0 ; i < 10; i++){
                if( count[i] % 2)
                    odd++;
            }
            if( odd <= 1)
                numPseudoPalindromic++;
            count[cur->val]--;
            return;
        }
        count[cur->val]++;
        if( cur->left )
            traverse(cur->left, count, numPseudoPalindromic);
        if( cur->right )
            traverse(cur->right, count, numPseudoPalindromic);
        count[cur->val]--;
    }
};
