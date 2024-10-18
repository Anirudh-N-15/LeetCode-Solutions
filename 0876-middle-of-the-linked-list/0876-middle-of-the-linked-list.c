/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode node ;
struct ListNode* middleNode(struct ListNode* head) 
{
    if(head==NULL)
    return NULL ;

    int i,count=0 ;

    node * temp = head ;
    node * current = head ;

    while(temp!=NULL)
    {
        temp = temp->next ;
         count++ ;
    }

    if(count%2==0)
    {
        for(i=0;i<count/2;++i)
        {
            current = current->next ;
        }
    }
    else
    {
        for(i=0;i<count/2;++i)
        {
            current = current->next ;
        }

    }
    return current ;
}