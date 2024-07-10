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
    long l = INT_MAX, r = INT_MAX;
    void lfun(TreeNode* root, int rval){
        if(root==NULL) return;
        if(root-> val != rval and root->val < l) l = root->val;
        lfun(root->left, rval);
        lfun(root->right, rval);
    }
    void rfun(TreeNode* root, int rval){
        if(root==NULL) return;
        if(root-> val != rval and root->val < r) r = root->val;
        rfun(root->left, rval);
        rfun(root->right, rval);
    }
    int findSecondMinimumValue(TreeNode* root) {
        l++;
        r++;
        lfun(root->left, root->val);
        rfun(root->right, root->val);
        if(l==INT_MAX+1L and r == INT_MAX+1L) return -1;
        if(l != root-> val and r != root->val){
            return min(l, r);
        }
        else if(l != root-> val) return l;
        else if(r != root->val) return r;
        else return -1;
        

    }
};