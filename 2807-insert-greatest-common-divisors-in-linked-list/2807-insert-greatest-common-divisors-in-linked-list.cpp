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

    int gcd(int a,int b){
        if(a==0) return b ;
        if(b==0) return a ;
        if(a==b) return a ;

        if(a>b)
            return gcd(a-b,b);
        else    
            return gcd(b-a,a);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * prev = head ;
        ListNode * current = head->next ;

        while(current!=NULL){
            ListNode * node = new ListNode(gcd(prev->val,current->val));

            prev->next = node ;
            node->next = current ;
            prev = current ;
            current = current->next ;
        }
        return head ;
    }
};