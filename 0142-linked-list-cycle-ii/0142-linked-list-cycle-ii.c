/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL || head->next==NULL)
    return NULL ;

    struct ListNode * sptr = head ;
    struct ListNode * fptr = head ;

    while(fptr && fptr->next)
    {
        sptr = sptr->next;
        fptr= fptr->next->next;

        if(fptr==sptr)
        {
            sptr = head ;

            while(sptr!=fptr)
            {
                sptr = sptr->next;
                fptr = fptr->next ;
            }
            return sptr ;
        }
    }
    return NULL ;
}