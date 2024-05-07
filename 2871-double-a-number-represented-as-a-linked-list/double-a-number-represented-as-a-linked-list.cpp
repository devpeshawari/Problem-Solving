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
    int solve(ListNode * node){
        if(node == NULL){
            return 0;
        }
        int temp = node->val * 2 + solve(node->next);
        node->val = temp%10;
        if(temp >= 10){
            return 1;
        }
        return 0;
    }
    
    
    ListNode* doubleIt(ListNode* head) {
        
        int temp = solve(head);
        if(temp == 1){
            ListNode * node = new ListNode(1);
            node->next = head;
            return node;
        }

        return head;
    }
};