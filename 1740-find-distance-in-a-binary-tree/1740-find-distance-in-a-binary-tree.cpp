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
    int dfs(TreeNode* root, int f, int p, int q){
        if(root == NULL) return 0;
        int l = dfs(root->left, f+1, p, q);
        int r = dfs(root->right, f+1, p, q);
        if(l > 0 and r > 0) {
            return l+r-(2*f);
        }
        
        if(root -> val == p or root->val == q){
           
            return abs(l+r - f);
        
        }
        return l+r;
    }

    int findDistance(TreeNode* root, int p, int q) {
        if(p == q) return 0;
        return dfs(root, 0, p, q);
    }
};