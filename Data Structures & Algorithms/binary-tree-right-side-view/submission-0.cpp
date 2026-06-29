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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        queue<TreeNode*> q;
        q.push(root);

        if(root == nullptr){
            return result;
        }

        while(!q.empty()){
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                TreeNode* nextNode = q.front();
                q.pop();
                
                if(i == levelSize - 1){
                    result.push_back(nextNode->val);
                }

                if(nextNode->left != nullptr){
                    q.push(nextNode->left);
                }

                if(nextNode->right != nullptr){
                    q.push(nextNode->right);
                }
            }
        }
        return result;   
    }
};
