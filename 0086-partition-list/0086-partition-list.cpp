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
    ListNode* partition(ListNode* head, int x) {
        //This question is similar to splitting neg and pos values in an array question.
        //Maintain two lists and add to those list depending on the value

        ListNode* A = new ListNode(); //Dummy heads
        ListNode* B = new ListNode();
        ListNode* Apoint = A, *Bpoint = B; //Two pointers for list

        while(head) {
            if(head->val < x) {
                Apoint->next = head ;
                Apoint = Apoint->next ;
            } else {
                Bpoint->next = head ;
                Bpoint = Bpoint->next ;
            }
            head = head->next ;
        }

        Bpoint->next = nullptr ; //Because B may still point to some other val in orig LL
        Apoint->next = B->next; //A and B are dummy nodes so The real nodes start from imm next

        return A->next ;
    }
};