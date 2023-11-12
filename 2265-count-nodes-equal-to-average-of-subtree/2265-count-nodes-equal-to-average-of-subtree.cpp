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
    int cc = 0;
    pair<int, int> fun(TreeNode* root){
        if(root == nullptr) {
            return {0, 0};
        }

        auto l = fun(root->left);
        auto r = fun(root->right);
        int s = 0;
        int c = l.second + r.second;
        c++;
        s+=root->val;
        s+=l.first;
        s+=r.first;
        if(root->val == s/c) cc++;
        return {s, c};
    }
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return cc;
    }
};