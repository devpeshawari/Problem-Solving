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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        vector<ListNode *> sol(k);
        ListNode * node = head;
        while(node != NULL){
            n++;
            node = node->next;  
        }
        int parts = n/k;
        int rem = n%k;
        cout << n;
        int i = 0;
        if(parts == 0){
            while(head != NULL){
                ListNode * temp = head;
                head = head->next; 
                temp->next = NULL;
                sol[i] = (temp);
                i++;   
            }
        }
        else{
            for(int j = 0; j < k; j++){
                int count = parts;
                if(rem > 0) count++;
                rem--;
                ListNode * temp = head;
                ListNode * start = head;
                count--;
                while(count){
                    temp = temp->next;  
                    count--;
                }
                if(temp != NULL && temp->next != NULL) head = temp->next;
                if(temp != NULL && temp->next != NULL) temp->next = NULL;
                sol[j] = start;
            }
        }
        

        return sol;
    }
};