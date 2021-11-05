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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vec;
        vector<int> idxes;
        
        while(head) vec.push_back(head->val), head = head->next;
        
        for(int i=1;i+1<vec.size();i++)
        {
            if(vec[i] > vec[i-1] && vec[i] > vec[i+1]) idxes.push_back(i);
            else if(vec[i] < vec[i-1] && vec[i] < vec[i+1]) idxes.push_back(i);
        }
        
        if(idxes.size() <= 1) return {-1, -1};
        
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        
        maxDist = idxes.back() - idxes.front();
        
        for(int i=1;i<idxes.size();i++) minDist = min(minDist, idxes[i]-idxes[i-1]);
        
        return {minDist, maxDist};
    }
};
