/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node ;

node * CreateNode(int num){
    node * newnode = (node * )malloc(sizeof(node));
    newnode->left = NULL ;
    newnode->right = NULL ;
    newnode->val = num ;

    return newnode ;
}

int LinearSearch(int * inorder,int inorderstart,int inorderend,int key){
    for(int i=inorderstart;i<=inorderend;++i)
    {
        if(inorder[i]==key)
        return i;
    }
    return -1 ;
}

node * TreeBuilding(int* inorder, int inorderSize, int* postorder, int postorderSize,int inorderstart,int inorderend,int * postorderindex){

    if(inorderstart>inorderend)
    return NULL ;

    int rootval = postorder[*postorderindex];
    node * root = CreateNode(rootval);
    (*postorderindex)-- ;

    if(inorderstart==inorderend)
    return root ;

    int inorderindex = LinearSearch(inorder,inorderstart,inorderend,rootval);

    root->right = TreeBuilding(inorder,inorderSize,postorder,postorderSize,inorderindex+1,inorderend,postorderindex);
    root->left = TreeBuilding(inorder,inorderSize,postorder,postorderSize,inorderstart,inorderindex-1,postorderindex);

    return root;
}


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {

    int postorderindex=postorderSize-1;

    return TreeBuilding(inorder,inorderSize,postorder,postorderSize,0,inorderSize-1,&postorderindex);
}