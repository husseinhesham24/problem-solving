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

    unordered_map<int, int>h;
    int maxi=INT_MIN;
    void solve(TreeNode* root)
    {
        if(!root)
        {
            return;
        }

        h[root->val]++;
        maxi = max(maxi, h[root->val]);
        solve(root->left);
        solve(root->right);
    }


    vector<int> findMode(TreeNode* root) {
        solve(root);
        vector<int>ans;
        for(auto it:h)
        {
            if(it.second==maxi)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};