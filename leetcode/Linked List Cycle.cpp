/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode *, int>h;
        ListNode *temp = head;
        while(temp)
        {   
            if(h[temp]==1)
            {
                return true;
            }
            h[temp] = 1;
            temp = temp->next;
        } 

        return false;
    }
};