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
    ListNode* rev(ListNode* head)
    {
        ListNode* h = NULL;
        while(head!=NULL)
        {
            ListNode *tmp = new ListNode();
            tmp->val = head->val;
            head = head->next;
            tmp->next = h;
            h = tmp;
        }
        return h;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        
        ListNode *p = head;
        ListNode *r = rev(head);
        while(p!=NULL && head!=NULL)
        {
            if(p->val!=r->val)
            {
                return false;
            }
            p = p->next;
            r = r->next;
        }
        return true;
    }
};