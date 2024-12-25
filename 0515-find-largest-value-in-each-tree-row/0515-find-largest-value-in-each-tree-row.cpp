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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q ;
        q.push(root);
        vector<int> ans ;
        if(!root){
            return ans ;
        }
        while(!q.empty()){
            int levelsize = q.size();
            vector<int> level ;
            
            for(int i=0;i<levelsize;++i){
                TreeNode * current = q.front();
                q.pop();
                level.push_back(current->val);

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            ans.push_back(*max_element(level.begin(),level.end()));
        }

        return ans ;
    }
};