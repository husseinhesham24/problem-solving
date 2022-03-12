/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>m;
        Node* it = head;
        while(it!=NULL)
        {
            m[it] = new Node(it->val);
            it = it->next;
        }
        
        it = head;
        while(it!=NULL)
        {
            m[it]->next = m[it->next];
            m[it]->random = m[it->random];
            it = it->next;
        }
        
        return m[head];
    }
};
