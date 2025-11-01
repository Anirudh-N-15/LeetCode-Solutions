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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> uset(nums.begin(),nums.end());

        ListNode * dummy = new ListNode(0,head);
        ListNode * prev = dummy ;
        ListNode * curr = head ;

        while(curr) {
            if(uset.find(curr->val) != uset.end()) {
                prev->next = curr->next ;
                curr = curr->next ;
            } else {
                curr = curr->next ;
                prev = prev->next ;
            }
        }
        return dummy->next ;
    }
};