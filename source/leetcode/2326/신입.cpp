/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};
    
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        
        int r = 0;
        int c = 0;
        int dir = 0;
        
        while(head)
        {
            res[r][c] = head->val;
            
            int nr = r + dr[dir], nc = c + dc[dir];
            if(nr >= m || nr < 0 || nc >= n || nc < 0 || res[nr][nc] != -1) dir = (dir+1)%4;
            
            r += dr[dir], c += dc[dir];
            
            head = head->next;
        }
        
        return res;
    }
};
