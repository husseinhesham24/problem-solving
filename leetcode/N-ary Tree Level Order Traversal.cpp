/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        vector<pair<int,int>>x;
        queue<pair<Node*,int>>q;
        q.push({root,1});
        int n = 1;
        while(!q.empty())
        {
            pair<Node*,int> temp = q.front();
            q.pop();
            x.push_back({temp.first->val, temp.second});
            
            for(auto it:temp.first->children)
            {
                n = temp.second+1;
                q.push({it, temp.second+1});
            }
        }
        
        ans.resize(n);
        for(auto it:x)
        {
            ans[it.second-1].push_back(it.first);
        }
        
        done:
        return ans;
    }
};