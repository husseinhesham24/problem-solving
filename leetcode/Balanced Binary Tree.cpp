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
    int mini = INT_MAX, maxi = INT_MIN;
    int solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int dl = solve(root->left);
        int dr = solve(root->right);

        if(dl==-1 || dr==-1 || abs(dl-dr)>1)
        {
            return -1;
        }

        return max(dl, dr)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }

        if(solve(root)==-1)
        {
            return false;
        }

        return true;
    }
};