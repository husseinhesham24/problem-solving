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
    unordered_map<int, pair<double, double>>mp;
    int maxi=1;
    void solve(TreeNode* node, int lvl)
    {
        if(node==NULL)
        {
            maxi = max(maxi, lvl-1);
            return;
        }
        mp[lvl].first+=node->val;
        mp[lvl].second++;
        
        solve(node->left,lvl+1);
        solve(node->right,lvl+1);
        return;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root,1);
        vector<double>x;
        for(int i=1;i<=maxi;i++)
        {
            x.push_back(mp[i].first/mp[i].second);
        }
        return x;
    }
};