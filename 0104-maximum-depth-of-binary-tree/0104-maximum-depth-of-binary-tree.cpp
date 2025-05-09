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
    int ans = 0;
    int maxDepth(TreeNode* root) {
        if(!root) return 0 ;
        maximumDepth(root,ans);
        return ans+1 ;
    }
private:
    void maximumDepth(TreeNode * root,int depth) {
        if(!root) return;

        if(!root->left && !root->right){
            ans = max(ans,depth);
        }

        maximumDepth(root->left,depth+1);
        maximumDepth(root->right,depth+1);

    }    
};