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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* head1 = new ListNode(0,head);
        ListNode* it = head1;

        while(it->next!=NULL && it->next->next!=NULL)
        {
            if(it->next->val==it->next->next->val)
            {
                int key = it->next->val;
                while(it->next!=NULL && it->next->val==key)
                {
                    it->next = it->next->next;
                }
            }
            else
            {
                it = it->next;
            }
        }
        
        
        return head1->next;
    }
};
