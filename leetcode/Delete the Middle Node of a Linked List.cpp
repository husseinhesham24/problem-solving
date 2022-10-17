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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        
        if(cnt==1)
        {
            return NULL;
        }
        
        temp = head;
        int flag = 0;
        
        if((cnt/2)==cnt-1)
        {
            while(temp->next->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
        else
        {
            while(temp->next->next!=NULL)
            {
                if(flag>=(cnt/2))
                {
                    temp->val = temp->next->val;
                }
                temp = temp->next;
                flag++;
            }

            temp->val = temp->next->val;
            temp->next = NULL;
         }
        return head;
    }
    
};