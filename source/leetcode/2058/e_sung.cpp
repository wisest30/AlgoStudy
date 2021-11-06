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
        vector<int> Node;
        vector<int> Address;
        vector<int> ret;
        while(head->next != nullptr){
        	Node.push_back(head->val);
        	head = head->next;
        }
        Node.push_back(head->val);
	    int size_list = Node.size();
        if(size_list < 3){
        	ret.push_back(-1);
        	ret.push_back(-1);
        }
        else{
        	for(int i = 1; i < size_list - 1; i++){
        		if((Node[i - 1] < Node[i] && Node[i + 1] < Node[i]) || (Node[i - 1] > Node[i] && Node[i + 1] > Node[i]))
        			Address.push_back(i + 1);
        	}
        	int min = INT_MAX;
            int size_address = Address.size();
            if(size_address < 2){
                ret.push_back(-1);
                ret.push_back(-1);
            }
            else{
                for(int i = 1; i < size_address; i++){
                    int tmp = Address[i] - Address[i - 1];
                    if(min > tmp)
                        min = tmp;
                }
                ret.push_back(min);
                ret.push_back(Address[size_address - 1] - Address[0]);
            }
        }
        return ret;
    }
};
