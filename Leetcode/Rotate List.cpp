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
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode* it = head;
        int n=1;
        
        //get the length of list 
        while(it!=NULL && it->next!=NULL)
        {
            n++;
            it = it->next;
        }
        
        if(head==NULL || k%n==0)
        {
            return head;
        }
        
        //make it circular linked list
        it->next = head;
        
        int pos_head=n-(k%n);
        int i=0;
        it = head;
        ListNode* tail = head;
        while(i<pos_head)
        {
            it = it->next;
            if(i>0)
            {
                tail = tail->next;
            }
            i++;
        }
        
        head = it;
        tail->next = NULL;
                         
        
        return head;
    }
};