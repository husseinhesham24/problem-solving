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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* t1 = head;
        int n=0;
        
        //get list_size
        while(t1)
        {
            n++;
            t1 = t1->next;
        }
        

        
        n = (n-k)+1;
        if(n==k)
        {
            return head;
        }
        
        
        t1 = head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        int i=1;
        while(t1)
        {
            if(i==k)
            {
                p1 = t1;
            }
            
            if(i==n)
            {
                p2 = t1;
            }
            
            i++;
            t1 = t1->next;
        }
        
        swap(p1->val, p2->val);
        
        return head;
    }
};









