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
    vector<vector<int>> spiralMatrix(int r, int c, ListNode* head) {
        int dy[4] = {0, 1, 0, -1};
        int dx[4] = {1, 0, -1, 0};
        
        auto ret = vector<vector<int>>(r, vector<int>(c, -1));
        int y = 0, x = 0, d = 0;
        
        for(auto h = head; h; h = h->next) {
            ret[y][x] = h->val;
            
            auto ny = y + dy[d];
            auto nx = x + dx[d];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || ret[ny][nx] != -1) {
                d = (d + 1) % 4;
                ny = y + dy[d];
                nx = x + dx[d];
            }

            swap(y, ny), swap(x, nx);
        }
        
        return ret;
    }
};
