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
        if(root == NULL) return {};
        queue<pair<TreeNode*, int>> q;
        int cl = 0;
        q.push({root, 0});
        vector<int> result;
        int s = 0;
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level == s){
                result.push_back(temp->val);
                s++;
            }
            if(temp->right != NULL){
               q.push({temp->right, level+1});
            }
            if(temp->left != NULL){
               q.push({temp->left, level+1});
            }
        }
        return result;
    }
};