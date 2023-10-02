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
    int ans=0;
    void solve(TreeNode* root, int depth)
    {
        if(root==NULL)
        {
            ans = max(depth-1, ans);
            return;
        }

        solve(root->left, depth+1);
        solve(root->right, depth+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }

        solve(root, 1);
        return ans;
    }
};