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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==right)
        {
            return head;
        }
        

        stack<ListNode*>s;
        ListNode* st = head;
        ListNode* temp = head;
        ListNode* en = head;
        ListNode* en_1 = head;

        int i=0, n=0;
        while(temp)
        {
            i++;
            n++;
            if(i+1==left)
            {
                st = temp;
            }
            
            if(i==right+1)
            {
                en = temp;
            }
            
            if(i==right)
            {
                en_1 = temp;
            }

            if(i>=left && i<=right)
            {
                s.push(temp);
            }
            temp = temp->next;
        }
        
        temp = head;
        
        if(left==1)
        {
            head = en_1;
            st = head;
            s.pop();
        }

        
        while(!s.empty())
        {
            ListNode* temp1 = s.top();
            s.pop();
            st->next = temp1;
            st = st->next;
        }

        //cout<<right<<" a "<<n<<" b "<<left<<" c "<<endl;
        if(right<n)
        {
            //cout<<"lol"<<endl;
            st->next = en;
        }
        else
        {
            st->next = nullptr;
        }
        return head;
    }
};