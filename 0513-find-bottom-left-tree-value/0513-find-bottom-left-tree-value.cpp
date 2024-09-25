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
     int ans = -1 ;
     int max_level = -1 ;

    void dfs(TreeNode * root,int level){

        if(root==NULL)
        return ;

        if(level > max_level){
            ans = root->val ;
            max_level = level ;
        }

        dfs(root->left,level+1);
        dfs(root->right,level+1);

    }

public:


    int findBottomLeftValue(TreeNode* root) {
        int level =0 ;

        dfs(root,level);

        return ans ;
    }
};