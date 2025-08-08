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
    ListNode * insert(ListNode* head, ListNode * node) {
        node->next = head ;
        head = node ;
        return head ;
    }

    struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
            return a->val < b->val; // min-heap by value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr ;
        }
        bool flag = false ;
        for(auto it : lists) {
            if(it != nullptr) {
                flag = true ;
            }
        }
        if(flag == false) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>,cmp> pq ;

        for(auto list: lists) {
            ListNode * ptr = list ;
            while(ptr){
                ListNode * node = new ListNode(ptr->val);
                pq.push(node);
                ptr = ptr->next ;
            }
        }

        ListNode * head =  pq.top();
        pq.pop();

        while(!pq.empty()) {
            ListNode * temp = pq.top();
            pq.pop();

            head = insert(head,temp);
        }
        return head ;
    }
};