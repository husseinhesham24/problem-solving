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
    
    void push(ListNode **head, int n)
    {
        ListNode* new_node = new ListNode(n);

        if(*head==NULL)
        {
            *head = new_node;
            return;
        }
        
        ListNode* it = *head;
        
        while(it->next!=NULL)
        {
            it = it->next;
        }
        
        it->next = new_node;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = NULL;
        int rem = 0;
        while(l1!=NULL && l2!=NULL)
        {
            int res = l1->val+l2->val+rem;
            if(res>9)
            {
                rem = 1;
                push(&head, res%10);
            }
            else
            {
                rem = 0;
                push(&head, res);
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=NULL)
        {
            int res = l1->val+rem;
            if(res>9)
            {
                rem = 1;
                push(&head, res%10);
            }
            else
            {
                rem = 0;
                push(&head, res);
            }
            l1 = l1->next;
        }
        
        while(l2!=NULL)
        {
            int res = l2->val+rem;
            if(res>9)
            {
                rem = 1;
                push(&head, res%10);
            }
            else
            {
                rem = 0;
                push(&head, res);
            }
            l2 = l2->next;
        }
        
        if(rem==1)
        {
            push(&head, rem);
        }
        return head;
    }
    
    
    
    
    
    
    
};