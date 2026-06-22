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
    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN, INT_MAX);   
    }

private:
    bool validate(TreeNode* node, int lower, int upper){
        if(node == nullptr){
            return true;
        }

        else if((node->val <= lower) || (node->val >= upper)){
            return false;
        }

        return (validate(node->left, lower, node->val) && validate(node->right, node->val, upper));
    }
};
