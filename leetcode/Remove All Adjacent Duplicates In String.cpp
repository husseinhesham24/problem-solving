class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto c:s)
        {
            if(!st.empty() && st.top()==c)
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        
        s = "";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};