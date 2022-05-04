/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    long long x;
    bool check(TreeNode* root , long long low , long long high)
    {
        if(root==NULL)
            return true;
        if(low != x && root->val <= low)
        {
            return false;
        }
        if(high != x && root->val >= high)
        {
            return false;  
        }
        return true && check(root->left , low , root->val) && check(root->right , root->val , high);
    }
    
    
    
    
    
    bool isValidBST(TreeNode* root  ) {
        
        if(root==NULL)
            return true;
        x = 100000000000;
        return check(root , x , x);
    }
};