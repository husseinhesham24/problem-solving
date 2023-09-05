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
        Node* i = head;
        Node* head1 = NULL;
        Node* j = head1;

        while(i)
        {
            Node* new_node = new Node(i->val);
            if(!head1)
            {
                head1 = new_node;
                j = head1;
            }
            else
            {
                j->next = new_node;
                j = j->next;
            }

            i = i->next;
        }

        

        i = head;
        j = head1;

        while(i)
        {
            if(i->random)
            {
                Node* k = head;
                Node* k1 = head1;
                while(i->random!=k)
                {
                    k = k->next;
                    k1 = k1->next; 
                }

                j->random = k1;
            }   

            i = i->next;
            j = j->next;
        }

        return head1;
    }
};