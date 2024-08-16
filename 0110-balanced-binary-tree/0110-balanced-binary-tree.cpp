/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int x = dfsHeight(root);
        return x != -1 ;
    }

    int dfsHeight(TreeNode * root){
        if(root==NULL)
        return 0 ;

        int LeftHeight = dfsHeight(root->left);
        if(LeftHeight== -1) return -1 ;
        int RightHeight = dfsHeight(root->right);
        if(RightHeight== -1) return -1 ;

        if(abs(LeftHeight - RightHeight)>1) return -1 ;
        return max(LeftHeight,RightHeight)+1 ;
    }
};