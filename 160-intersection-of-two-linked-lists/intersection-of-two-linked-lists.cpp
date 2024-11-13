/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int calculateLength(ListNode * head){
        int sol = 0;
        while(head != NULL){
            sol++;
            head = head->next;
        }

        return sol;
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = calculateLength(headA);
        int l2 = calculateLength(headB);
        if(l1== 0 || l2 == 0){
            return NULL;
        }
        
        if(l1 < l2){    
            swap(headA,headB);
        }
        int diff = abs(l1 - l2);
        
        for(int i = 0; i < diff; i++){
            headA = headA->next;    
        }

        while(headA != NULL && headB != NULL){
            if(headA == headB){
                return headA;
            }
            cout << headA->val << " " << headB->val << "\n";
            headB = headB->next;
            headA = headA->next;
        }

        return NULL;
    }
};