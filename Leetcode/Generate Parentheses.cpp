class Solution {
public:
    
    vector<string>ans;
    int cnt=0;
    unordered_set<string>ss;
    int sz=0;
    
    bool valid(string x)
    {
        stack<char>s;
        for(int i=0;i<sz;i++)
        {
            if(x[i]=='(')
            {
                s.push(x[i]);
            }
            else
            {
                if(s.empty() || s.top()==')')
                {
                    return false;
                }
                else
                {
                    s.pop();
                }
            }
        }
        
        return s.empty();
    }
    
    void permut(string x, int l, int r)
    {
        
        if(ss.count(x))
        {
            return;
        }         
        if (l==r)
        {
            ss.insert(x);
            
            if(valid(x))
            {
                ans.push_back(x);
            }
        }
        
        
        for(int i=l;i<r;i++)
        {
            swap(x[l], x[i]);
            permut(x, l+1, r);
            swap(x[l], x[i]);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string x="";
        
        for(int i=0;i<n*2;i++)
        {
            if(i<((n*2)/2))
            {
                x+='(';
            }
            else
            {
                x+=')';
            }
        }
        
        sz=n*2;
        permut(x, 0, sz-1);
        return ans;
    }
};