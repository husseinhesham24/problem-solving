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
        int i = 0;
        ListNode* it = head;
        while(it!=NULL && i<10001)
        {
            it = it->next;
            i++;
        }
        
        return i==10001;
    }
};
