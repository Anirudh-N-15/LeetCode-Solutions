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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)
        return NULL ;
        ListNode * dummy = new ListNode(0) ;
        dummy->next = head ;

        int count =0;
        ListNode * ptr = head ;
        ListNode * prev = dummy ;

        while(ptr){
            count++ ;
            ptr = ptr->next ;
        }
        ptr = head ;

        for(int i=0;i<count-n;++i){
            prev = ptr ;
            ptr = ptr->next ;
        }
        prev->next = ptr->next ;

        return dummy->next ;
    }
};