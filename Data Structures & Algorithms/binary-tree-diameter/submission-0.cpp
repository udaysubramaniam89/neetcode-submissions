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
private:
    int diameter;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        diameter = 0;
        height(root);
        return diameter;
    }

private:
    int height(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int leftTreeHeight = height(node->left);
        int rightTreeHeight = height(node->right);
        diameter = max(diameter, leftTreeHeight + rightTreeHeight);
        return 1 + max(leftTreeHeight, rightTreeHeight);
    }
};
