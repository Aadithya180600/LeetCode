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
    string s = "";
    void fun(TreeNode* root){
        if(root == NULL) return;

        s+=to_string(root->val);
        if(root->left) {
            s+="(";
            fun(root->left);
            s+=")";
        }
        if(root->right) {
            if(!root->left) {s+="()";}
            s+="(";
            fun(root->right);
            s+=")";
        }
        
    }
    string tree2str(TreeNode* root) {
        fun(root);
        return s;
    }
};