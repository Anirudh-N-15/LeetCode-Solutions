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
        queue <TreeNode *> q ;
        vector<int> result ;
        q.push(root);

        while(!q.empty()){
            int levelsize = q.size();
            int sum = 0; 

            for(int i=0;i<levelsize;++i){
                TreeNode * node = q.front();
                q.pop();

                sum += node->val ;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(sum);
        }

        int max = INT_MIN ;
        int level = 0;
        for(int i=0;i<result.size();++i){
            if(result[i] > max){
                max = result[i] ;
                level = i ;
            }
        }

        return level+1 ;
    }
};