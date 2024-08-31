/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct {
    struct ListNode * Head ;
    int size ;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution * Random = (Solution *) malloc(sizeof(Solution));
    Random->Head = head ;
    struct ListNode* temp=head;
    int count = 0;

    while(temp!=NULL){
        temp = temp->next ;
        count++ ;
    }
    Random->size = count ;
    return Random ;
}

int solutionGetRandom(Solution* obj) {
    Solution * head = obj ;
    struct ListNode* temp=head->Head;
    
    int randomindex = rand() % (head->size) ;

    for(int i=0;i<randomindex;++i){
        
        temp = temp->next ;
    }
    return temp->val ;
}
void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/