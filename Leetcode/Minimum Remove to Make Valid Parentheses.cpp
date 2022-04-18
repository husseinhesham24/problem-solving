class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>st;
        vector<int>pos;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]==')' )
            {
                if(st.empty())
                {
                    st.push(s[i]);
                    pos.push_back(i);
                }
                else if(st.top()=='(' && s[i]==')')
                {
                    st.pop();
                    pos.pop_back();
                }
                else
                {
                    st.push(s[i]);
                    pos.push_back(i);
                }
            }
        }
        
        string ans="";
        int n = pos.size();
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(j<n && i==pos[j])
            {
                j++;
            }
            else
            {
                ans+=s[i];
            }
        }
        
        return ans;
    }
};