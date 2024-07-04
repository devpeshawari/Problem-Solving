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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * sol;;
        ListNode * node = new ListNode(0);
        sol = node;
        int temp = 0;
        head = head->next;
        while(head != NULL){
            if(head->val == 0){
                node->val = temp;
                ListNode * empty = new ListNode(0);
                if(head->next != NULL){
                    node->next = empty;
                    node = node->next;
                }
                temp = 0;
            }
            temp += head->val;
            head = head->next;
        }    
        
        return sol;
    }
};