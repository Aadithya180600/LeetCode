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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if((p == NULL || q == NULL) || (p->val!=q->val)) return false;
        stack<TreeNode*> s,r;
        s.push(p);
        r.push(q);
        while(!s.empty() && !r.empty()) {
            TreeNode* a = s.top();
            TreeNode* b = r.top();
            if(a->val!=b->val) return false;
            s.pop(),r.pop();
            if(a->left && b->left) s.push(a->left),r.push(b->left);
            else if(a->left || b->left) return false;
            if(a->right && b->right) s.push(a->right),r.push(b->right);
            else if(a->right || b->right) return false;
        }
        if(s.empty() && r.empty()) return true;
        return false;
    }
};