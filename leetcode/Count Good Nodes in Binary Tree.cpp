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
    int ans = 0;
    int solve(TreeNode* root, int maxi)
    {
        if(root==NULL)
            return 0;
        
        if((root->val)<maxi)
        {
            solve(root->left, maxi);
            solve(root->right, maxi);
        }
        else
        {
            maxi = root->val;
            ans++;
            solve(root->left, maxi);
            solve(root->right, maxi);
        }   
        return ans;
    }
    
    int goodNodes(TreeNode* root) {
        int maxi = root->val;
        return solve(root, maxi);
        
    }
};