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
    vector<int> v;
    int max = INT_MIN;
    int prev = max;
    int c = 1;
    void fun(TreeNode* root){
        if(root == NULL)
            return;
        fun(root->left);
        if(root->val == prev) c++;
        else c = 1;
        prev = root->val;

        if(c==max){
            v.push_back(root->val);
        }
        else if(c>max){
            v.clear();
            v.push_back(root->val);
            max = c;
        }
        fun(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        fun(root);
       
        return v;
    }
};