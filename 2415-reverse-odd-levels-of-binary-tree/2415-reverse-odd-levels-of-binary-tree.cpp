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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return nullptr ;

        int level = 1 ;

        helperReverse(root->left,root->right,level);
        return root ;
    }
private:
    void helperReverse(TreeNode * left,TreeNode * right,int level){
        if(!left || !right){
            return ;
        }
        if(level%2 ==1){
            swap(left->val,right->val);
        }

        helperReverse(left->left,right->right,level+1);
        helperReverse(left->right,right->left,level+1);
    }
};