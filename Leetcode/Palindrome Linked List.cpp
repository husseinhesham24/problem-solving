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

#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *p = head;
        vector<int>x;
        while(p!=NULL){
            x.push_back(p->val);
            p = p->next;
        }
        
        p = head;
        while(p!=NULL){
            if(p->val!=x.back())
            {
                return false;
            }
            p = p->next;
            x.pop_back();
        }
        return true;
    }
};