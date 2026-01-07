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
    const long long mod = 1e9 + 7;
    long long total = 0;
    long long ans = 0;

    long long sumTree(TreeNode* root) {
        if (!root) return 0;

        long long left  = sumTree(root->left);
        long long right = sumTree(root->right);

        return root->val + left + right;
    }

    long long dfs(TreeNode * root) {
        long long sub = 0;
        if(!root) {
            return 0;
        }

        sub = root->val + dfs(root->left) + dfs(root->right) ;

        long long product = sub * (total - sub) ;
        ans = max(product,ans);

        return sub ;
    }

    int maxProduct(TreeNode* root) {
        total = sumTree(root);
        dfs(root);

        return ans % mod ;
    }
};