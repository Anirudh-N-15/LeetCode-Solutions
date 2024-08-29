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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * ptr1 = list1 ;
        ListNode * ptr2 = list2 ;
        ListNode * ptr3 = list1 ;

        for(int i=0;i<b;++i){
            ptr3 = ptr3->next ;
        }

        for(int i=0; i<a-1; ++i){
            ptr1 = ptr1->next ;
        }
        ptr1->next = ptr2 ;

        while(ptr2->next!=NULL){
            ptr2 = ptr2->next ;
        }
        
        ptr2->next = ptr3->next ;

        return list1 ;
    }
};