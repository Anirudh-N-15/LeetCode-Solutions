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
    vector<int> nodes;
    vector<int> prefixSum;
    void inorder(TreeNode *root,vector<int>& nodes) {
        if(root) {
            inorder(root->left,nodes);
            nodes.push_back(root->val);
            inorder(root->right,nodes);
        }
    }

    int compute(int node,vector<int>& nodes,vector<int>& prefixSum) {
        int ans = 0, n = nodes.size();
        for(int i=0;i<n;i++) {
            if(node == nodes[i]) {
                ans = prefixSum[n-1] - prefixSum[i] + nodes[i] ;
                break;
            }
        }
        return ans ;
    }

    void toGst(TreeNode * root) {
        if(root) {
            toGst(root->left) ;
            root->val = compute(root->val,nodes,prefixSum);
            toGst(root->right) ;
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        inorder(root,nodes);
        int n = nodes.size();
        prefixSum.push_back(nodes[0]);
        for(int i=1;i<n;i++) {
            prefixSum.push_back(nodes[i] + prefixSum[i-1]);
        }
        toGst(root);
        return root ;
    }
};