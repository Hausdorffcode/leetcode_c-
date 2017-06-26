//https://leetcode.com/problems/binary-tree-inorder-traversal/#/description

//stack记录回去的路，p指向将要考察的点
//time O(n), space O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> nodes;
        TreeNode* p = root;
        //if (root != nullptr) nodes.push(root);  //千万不要有这一句
        while (!nodes.empty() || p != nullptr) {
            if (p == nullptr) {
                p = nodes.top(); nodes.pop();
                ret.push_back(p->val);
                p = p->right;
            }
            else {
                nodes.push(p);
                p = p->left;
            }
        }
        return ret;
    }
};