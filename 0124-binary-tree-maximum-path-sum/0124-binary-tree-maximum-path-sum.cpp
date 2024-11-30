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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN ;
        maxPathDown(root,maxSum);
        return maxSum;
    }
private:
    int maxPathDown(TreeNode * node,int &maxSum){
        if(!node) return 0 ;

        int leftSum = max(0,maxPathDown(node->left,maxSum));
        int RightSum = max(0,maxPathDown(node->right,maxSum));

        maxSum = max(maxSum,leftSum + RightSum + node->val);

        return node->val + max(leftSum,RightSum);
    }    
};