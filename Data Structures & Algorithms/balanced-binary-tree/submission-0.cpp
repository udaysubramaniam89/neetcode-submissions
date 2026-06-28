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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1; 
    }

private:
    int checkHeight(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int leftTreeHeight = checkHeight(node->left);
        if(leftTreeHeight == -1){
            return -1;
        }

        int rightTreeHeight = checkHeight(node->right);
        if(rightTreeHeight == -1){
            return -1;
        }

        if(abs(leftTreeHeight - rightTreeHeight) > 1){
            return -1;
        }

        return 1 + max(leftTreeHeight, rightTreeHeight);

    }    
};
