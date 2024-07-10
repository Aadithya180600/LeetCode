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
    bool search(int sum, TreeNode* root, TreeNode* curr){
        if(root==NULL) return false;
        if(root->val == sum and curr!=root) return true;
        else if(root -> val > sum) return search(sum, root->left, curr);
        else {
            return search(sum, root->right, curr);
        }
    }
    bool preorder(TreeNode* root, int sum, TreeNode* Rroot){
        if(root == NULL) return false;
        bool l = preorder(root->left, sum, Rroot);
        if(search(sum - root->val, Rroot, root)) return true;
        bool r = preorder(root->right, sum, Rroot);
        return l or r;
    }
    bool findTarget(TreeNode* root, int k) {
        return preorder(root, k, root);
    }
};