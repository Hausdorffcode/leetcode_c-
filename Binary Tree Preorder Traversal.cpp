//https://leetcode.com/problems/binary-tree-preorder-traversal/#/description

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//use stack
//time O(n), space O(n); 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> sr;
        if (root != nullptr) sr.push(root);
        while (!sr.empty()) {
            TreeNode* node = sr.top(); sr.pop();
            ans.push_back(node->val);
            if (node->right != nullptr) sr.push(node->right);
            if (node->left != nullptr) sr.push(node->left);
        }
        return ans;
    }
};