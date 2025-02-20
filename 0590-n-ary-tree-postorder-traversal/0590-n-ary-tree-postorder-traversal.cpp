/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {

vector<int> result ;

void postOrder(Node * root){
    if(!root)
    return ;

    for(auto child : root->children){
        postOrder(child);
        result.push_back(child->val);
    }
}

public:
    vector<int> postorder(Node* root) {
        if(!root)
        return {};

        postOrder(root);
        result.push_back(root->val);

        return result ;
    }
};