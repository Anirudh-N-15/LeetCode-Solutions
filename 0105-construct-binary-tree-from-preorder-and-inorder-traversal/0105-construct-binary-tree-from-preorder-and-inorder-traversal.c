/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * CreateNode(int num)
{
    struct TreeNode * newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newnode->left = NULL ;
    newnode->right = NULL ;
    newnode->val = num ;
    return newnode; 
}

int LinearSearch(int *arr,int begin,int end,int key)
{
    for(int i=begin;i<=end;++i)
    {
        if(arr[i]==key)
        {
            return i ;
        }
    }
    return -1 ;
}

struct TreeNode* TreeBuilding(int* preorder, int preorderSize, int* inorder, int inorderSize,int inorderstart,int inorderend,int *preorderindex) {
    if(inorderstart>inorderend)
    return NULL ;

    int rootval = preorder[*preorderindex];
    (*preorderindex)++ ;

    struct TreeNode * root = CreateNode(rootval);

    if(inorderstart==inorderend)
    return root;

    int inorderindex = LinearSearch(inorder,inorderstart,inorderend,rootval);

    root->left = TreeBuilding(preorder,preorderSize,inorder,inorderSize,inorderstart,inorderindex-1,preorderindex);
    root->right = TreeBuilding(preorder,preorderSize,inorder,inorderSize,inorderindex+1,inorderend,preorderindex);

    return root;

}

struct TreeNode * buildTree(int * preorder,int preorderSize,int *inorder,int inorderSize)
{
    int preorderindex=0;

    return TreeBuilding(preorder, preorderSize, inorder,inorderSize,0,inorderSize-1,&preorderindex);
}
