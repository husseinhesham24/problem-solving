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
    
    int get_carry(ListNode **head, int res)
    {
        int carry;
        if(res>9)
        {
            carry = 1;
            push(head, res%10);
        }
        else
        {
            carry = 0;
            push(head, res);
        }
        return carry;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = NULL;
        int carry = 0;
        while(l1!=NULL && l2!=NULL)
        {
            int res = l1->val+l2->val+carry;
            carry = get_carry(&head, res);
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=NULL)
        {
            int res = l1->val+carry;
            carry = get_carry(&head, res);
            l1 = l1->next;
        }
        
        while(l2!=NULL)
        {
            int res = l2->val+carry;
            carry = get_carry(&head, res);
            l2 = l2->next;
        }
        
        if(carry==1)
        {
            push(&head, carry);
        }
        return head;
    }
};
