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
    void inorder(TreeNode * root, int& ans, int& prev, bool& hasPrev) {
        if(!root) return ;

        inorder(root->left, ans,prev,hasPrev);

        if(hasPrev) {
            ans = min(ans, abs(root->val - prev));
        }
        prev = root->val ;
        hasPrev= true ;

        inorder(root->right, ans, prev ,hasPrev);
    }

    int getMinimumDifference(TreeNode* root) {
        int prev = -1, ans = 1e6;
        bool hasPrev = false ;

        inorder(root,ans, prev, hasPrev);
        return ans ;
    }
};