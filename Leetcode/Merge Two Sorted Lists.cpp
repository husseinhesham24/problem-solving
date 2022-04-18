/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void append (ListNode* &head, int data)
    {
        ListNode* new_node = new ListNode;
        ListNode* last = head;
        new_node->val = data;
        new_node->next = NULL;
        
        
        if(head==NULL)
        {
            head = new_node;
            return;
        }
        
        while(last->next!=NULL)
        {
            last = last->next;
        }
        
        last->next = new_node;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = NULL;
        ListNode* it1 = list1;
        ListNode* it2= list2;
        
        while(it1!=NULL || it2!=NULL)
        {   
            if(it1!=NULL && it2!=NULL)
            {
                if(it1->val<it2->val)
                {
                    append(head, it1->val);
                    it1 = it1->next;
                }
                else
                {
                    append(head, it2->val);
                    it2 = it2->next;
                }
            }
            else if(it1!=NULL)
            {
                append(head, it1->val);
                it1 = it1->next;
            }
            else
            {
                append(head, it2->val);
                it2 = it2->next;
            }
        }
        
        return head;
    }
};