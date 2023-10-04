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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        
        if(!root)
        {
            return ans;
        }

        vector<vector<int>>arr;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            TreeNode* temp = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(arr.size()<=depth)
            {
                arr.push_back(vector<int>());
            }

            arr[depth].push_back(temp->val);

            if(temp->left)
            {
                q.push({temp->left, depth+1});
            }

            if(temp->right)
            {
                q.push({temp->right, depth+1});
            }
        }

        for(auto x:arr)
        {
            ans.push_back(x.back());
        }

        return ans;
    }
};