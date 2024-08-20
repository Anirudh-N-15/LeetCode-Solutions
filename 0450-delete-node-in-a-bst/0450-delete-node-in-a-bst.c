/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node ;

node * Findmin(node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root; 
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(root==NULL)
    return NULL ;

    if(key < root->val){
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->val){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            node * temp = root->right ;
            free(root);
            return temp ;
        }
        else if(root->right==NULL){
            node * temp = root->left;
            free(root);
            return temp ;
        }
          node * temp = Findmin(root->right);
          root->val = temp->val ;
          root->right = deleteNode(root->right,temp->val);
    }
    return root; 
}