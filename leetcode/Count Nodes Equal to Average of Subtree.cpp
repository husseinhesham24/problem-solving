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
    
    pair<int,int>solve(TreeNode* root, int &ans)
    {
        if(!root)
        {
            return {0,0};
        }

        auto [lsum, lcount] = solve(root->left, ans);
        auto [rsum, rcount] = solve(root->right, ans);

        int curr_sum = root->val+lsum+rsum;
        int curr_count = 1+lcount+rcount;
        if(curr_sum/curr_count==root->val)
        {
            ans++;
        }

        return {curr_sum, curr_count};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(root, ans);
        return ans;
    }
};