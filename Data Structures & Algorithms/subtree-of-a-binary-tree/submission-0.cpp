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
    bool sameTree(TreeNode* rootA, TreeNode* rootB){
        if(rootA == nullptr && rootB == nullptr){
            return true;
        }

        else if(rootA == nullptr || rootB == nullptr){
            return false;
        }

        else if(rootA->val != rootB->val){
            return false;
        }

        bool leftSide = sameTree(rootA->left, rootB->left);
        bool rightSide = sameTree(rootA->right, rootB->right);

        return leftSide && rightSide;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }

        else if(sameTree(root, subRoot)){
            return true;
        }

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};
