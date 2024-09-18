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
    int maxDepth(TreeNode* root) {

        // Checking for null root
        if(root == NULL) return 0;

        // Sentinal Technique - Adding Null after every level 
        // in BFS to know how many levels are there
        // Example: 3 NULL 9 20 NULL 15 7 NULL 
        // There are 3 NULLS in above code indicating 3 levels.

        // Count for number of levels
        int c = 0;
        
        // Queue for BFS
        queue<TreeNode*> q;

        // Add root and sentinal node - Null into queue
        // This will indicate level ends after reading root 
        q.push(root);
        q.push(NULL);

        // Traverse the queue
        while(!q.empty()){
            // Get the current node in front of the queue
            auto current = q.front();

            // Pop the front node
            q.pop();

            // If the current node is a sentinal node (NULL), 
            // It means a level ended and a new level is starting, increment the count.
            // That means the children of the next nodes will belong to another level.
            // Therefore, add a sentinal node in the back of the queue to say a new level is starting.
            if(current == NULL) {
                c++;
                
                // In the case of end of the queue, there will be NULL (refer the example above)
                // So, in this case, if we simply add another NULL by seeing the last NULL,
                // The code will go into infinte loop.
                // Therefore, check if there are any elements in the queue before adding the sentinal.
                if(!q.empty()) q.push(NULL);
                continue;
            }

            // Add left and right children in the queue.
            if(current->left != NULL) q.push(current->left);
            if(current->right != NULL) q.push(current->right);
        }

        // return the final count.
        return c;
    }
};
// Thank you for reading. please upvote if you find this helpful.