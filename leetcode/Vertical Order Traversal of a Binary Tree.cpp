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
    vector<pair<int, pair<int,int>>>x;
    
    void solve(TreeNode* node, int r, int c)
    {
        if(node==NULL)
        {
            return;
        }
        
        x.push_back({c, {r, node->val}});
        solve(node->left, r+1, c-1);
        solve(node->right, r+1, c+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);
        unordered_set<int>s;
        for(auto it: x)
        {
            s.insert(it.first);
        }
        
        sort(x.begin(), x.end());
        
        vector<vector<int>>ans(s.size());
        int last = x[0].first;
        ans[0].push_back(x[0].second.second);
        int j=0;
        for(int i=1;i<x.size();i++)
        {
            if(last==x[i].first)
            {
                ans[j].push_back(x[i].second.second);
                continue;
            }
            j++;
            last = x[i].first;
            ans[j].push_back(x[i].second.second);
        }
        return ans;
    }
};