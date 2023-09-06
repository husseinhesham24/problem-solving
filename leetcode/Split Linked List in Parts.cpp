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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* temp = head;
        while(temp)
        {
            n++;
            temp = temp->next;
        }

        int sz = n/k;
        int sz_m = n%k;

        vector<ListNode*>ans(k, nullptr);
        int j=0;
        temp = head;
        while(k-- && temp)
        {
            while(sz_m>0 && temp)
            {
                cout<<"noooooooo  "<<sz_m<<endl;
                ListNode* new_head = NULL;
                ListNode* new_temp = new_head;
                for(int i=0;i<=sz && temp;i++)
                {
                    ListNode* new_node = new ListNode(temp->val);
                    if(new_head==NULL)
                    {
                        new_head = new_node;
                        new_temp = new_head;
                    }
                    else
                    {
                        
                        new_temp->next = new_node;
                        new_temp = new_temp->next;
                    }
                    temp = temp->next;
                }

                ans[j++] = new_head;
                sz_m--;
            }
            
            if(temp)
            {
                ListNode* new_head = NULL;
                ListNode* new_temp = new_head;
                for(int i=0;i<sz && temp;i++)
                {
                    ListNode* new_node = new ListNode(temp->val);
                    if(!new_head)
                    {
                        new_head = new_node;
                        new_temp = new_head;
                    }
                    else
                    {
                        new_temp->next = new_node;
                        new_temp = new_temp->next;
                    }
                    temp = temp->next;
                }

                ans[j++] = new_head;
            }
        }

       
        return ans;
    }
};