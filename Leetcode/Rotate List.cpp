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
        vector<pair<int, int>>pos;
        ListNode* it = head;
        int n=0;
        while(it!=NULL)
        {
            n++;
            it = it->next;
        }
        
        it = head;
        int i=0;
        while(it!=NULL)
        {
            pos.push_back({(i+k)%n, it->val});
            i++;
            it = it->next;
        }
                         
        sort(pos.begin(), pos.end());
        
        it = head;
        i=0;
        while(it!=NULL)
        {
            it->val = pos[i].second;
            i++;
            it = it->next;
        }
        
        return head;
    }
};