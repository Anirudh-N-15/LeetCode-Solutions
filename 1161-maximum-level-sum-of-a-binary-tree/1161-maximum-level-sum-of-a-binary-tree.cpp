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
    int maxLevelSum(TreeNode* root) {
        int currLevel =1 ;
        queue<TreeNode *> q ;
        q.push(root);
        int maxSum = root->val ;

        int ansLevel = 1;
        while(!q.empty()) {
            int size = q.size();
            int currSum = 0;

            for(int i=0;i<size;i++) {
                TreeNode * curr = q.front();
                q.pop() ;

                currSum += curr->val ;

                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            currLevel++ ;

            if(maxSum < currSum) {
                maxSum = max(currSum,maxSum);
                ansLevel = currLevel ;
            }
        }

        return ansLevel-1 == 0 ? 1 : ansLevel-1 ;
    }
};