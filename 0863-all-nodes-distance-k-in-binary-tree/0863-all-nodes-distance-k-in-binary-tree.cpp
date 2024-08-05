class Solution {
public:
    vector<int> res;
    int l = 0;
    map<int, char> mp; 
    void funct(TreeNode* root, TreeNode* target, int k, int r){
        if(root == nullptr) return;
        if(root == target) return;
        if(k==r) {
            res.push_back(root->val);
            return;
        }
        if(mp.find(root->val) != mp.end()){
            if(mp[root->val] == 'L') {
                funct(root->left, target, k-1,r);
                funct(root->right, target, k+1, r);
            }
            else{
                funct(root->left, target, k+1, r);
                funct(root->right, target, k-1, r);
            }
        }
        else{
            funct(root->left, target, k+1, r);
            funct(root->right, target, k+1, r);
        }
    }
    bool fun(TreeNode* root, TreeNode* target, int m,int k){
        if(root == nullptr) return 0;
        if(k == 0) {
            res.push_back(root->val);
            return true;
        }
        if(root == target) {
            l = m;
            m=-1;
        }
        if(m==-1){
            fun(root->left, target, m, k-1);
            fun(root->right, target, m, k-1);
            return true;
        }
        else{
            bool l = fun(root->left, target, m+1, k);
            if(l) mp[root->val] = 'L';
            bool r = fun(root->right, target, m+1, k);
            if(r) mp[root->val] = 'R';
            return l or r;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        fun(root, target, 0, k);
        
        if(k == 0) return {target->val};
        int ll = l-k;
        int r = l;
        while(ll > 0){
            if(mp[root->val] == 'L') root = root->left;
            else root = root->right;
            ll--;
        }
        if(ll == 0){
            res.push_back(root->val);
            if(mp[root->val] == 'L') root = root->left;
            else root = root->right;
            r = k-1;
        }
        funct(root, target, r, k);
        return res;
    }
};