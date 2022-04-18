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
        unordered_map<int , int>h;
        ListNode* it = head;
        
        while(it!=NULL)
        {
            h[it->val]++;
            it = it->next;
        }
        
        it = head;
        ListNode* prev = head;
        ListNode* temp;
        bool flag = true;

        while(it!=NULL)
        {
            if(h[it->val]>1)
            {
                int key = it->val;
                while(it!=NULL && it->val==key)
                {
                    temp = it;
                    it = it->next;
                    //lete(temp);
                }
            }
            else
            {
                if(prev==head && flag)
                {
                    head = it;
                    flag = false;
                }
                else
                {
                    prev->next = it;
                }

                prev = it;
                it = it->next;
            }
        }
        
        
        if(head==NULL || h[head->val]>1)
        {
            head = NULL;
        }
        else
        {
            prev->next = it;
        }
        
        return head;
    }
};