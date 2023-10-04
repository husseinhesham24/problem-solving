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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
        {
            return ans;
        }

        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            TreeNode* temp = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(ans.size()<=depth)
            {
                vector<int>x;
                ans.push_back(x);
            }

            ans[depth].push_back(temp->val);
            if(temp->left!=NULL)
            {
                q.push({temp->left, depth+1});
            }
           
            if(temp->right!=NULL)
            {
                q.push({temp->right, depth+1});
            }
        }

        return ans;
    }
};