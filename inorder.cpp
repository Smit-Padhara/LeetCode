#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        inorder(root->left, res);       // Left
        res.push_back(root->val);       // Root
        inorder(root->right, res);      // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};
