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


    bool isCompleteTree(TreeNode* root) {
        bool last_c = true, last_r = true;
        queue<TreeNode*>q;
        
        q.push(root);
        TreeNode* p;
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            if(!p->left && !p->right)
            {
                last_r = false;
                continue;
            }
            else if(!p->left)
            {
                return false;
            }
            else if(!p->right)
            {
                if(last_c && last_r)
                {
                    q.push(p->left);
                    last_c = false;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(last_c && last_r)
                {
                    q.push(p->left);
                    q.push(p->right);
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};