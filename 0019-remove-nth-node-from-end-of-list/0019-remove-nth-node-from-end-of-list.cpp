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
        //Use fast and slow pointer technique, walk fast pointer n steps and then
        //keep slow pointer static. Then update them normally
        if(head == nullptr || head->next == nullptr) {
            return nullptr ;
        }

        ListNode * slow = head, *fast = head;

        while(n--) {
            if(fast->next == nullptr) {
                return head->next;
            }
            fast = fast->next ;
        }
        while(fast->next) {
            fast = fast->next ;
            slow = slow->next ;
        }

        if(slow->next != nullptr) {
            slow->next = slow->next->next ;
        }

        return head ;
    }
};