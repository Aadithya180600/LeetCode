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
    double avg = 0;
    pair<long long, int> fun(TreeNode* root){
        if(root == NULL){
            return make_pair(0,0);
        }
        auto l = fun(root->left);
        auto r = fun(root->right);
        long long sum = l.first + r.first + root->val;
        int count = l.second+r.second+1;
        double a = (double)(sum)/(count);
        // if(l.first ==  and r==-1){
        //     a = root->val;
        // }
        // else if(l==-1 or r == -1){
        //     a = (l+r+root->val)/2;
        // }
        // else a = (l+r+root->val)/3;
        avg = max(a, avg);
        return make_pair(sum, count);
    }
    double maximumAverageSubtree(TreeNode* root) {
        fun(root);
        return avg;
    }
};