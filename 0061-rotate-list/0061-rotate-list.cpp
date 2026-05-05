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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr ;
        ListNode * ptr = head;
        ListNode * curr = head;
        int n = 0;
        while(ptr->next) {
            n++ ;
            ptr = ptr->next ;
            curr = curr->next ;
        }
        n++ ;
        k = k % n ;
        if(k == 0) return head ;
        ptr = head; 

        for(int i=0;i<n-k-1;i++) {
            ptr = ptr->next ;
        }

        curr->next = head ;
        head = ptr->next  ;
        ptr->next = nullptr ;
        return head ;
    }
};