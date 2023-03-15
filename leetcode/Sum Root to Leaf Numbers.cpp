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
    void solve(TreeNode* r, int sum)
    {
        if(!r)
        {
            return;
        }

        sum = ((sum*10)+r->val);
    
        if(!r->left && !r->right)
        {
            ans+=sum;
            //cout<<sum<<" "<<flag<<endl;
        }

        solve(r->left, sum);
        solve(r->right, sum);
    
    }
    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};