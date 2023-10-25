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
   
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root)
        {
            return ans;
        }
        
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        int last = 0;
        int maxi=INT_MIN;
        //ans.push_back(root->val);
        while(!q.empty())
        {
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            int data = temp.first->val;
            int level = temp.second;
            //cout<<data<<" "<<level<<" "<<last<<endl;
            if(level>last)
            {
                ans.push_back(maxi);
                maxi = data;
                last = level;
            }
            else
            {
                maxi = max(data, maxi);
            }

            if(temp.first->left)
            {
                q.push({temp.first->left, level+1});
            }

            if(temp.first->right)
            {
                q.push({temp.first->right, level+1});
            }
        }  

        ans.push_back(maxi);
        return ans; 
    }
};