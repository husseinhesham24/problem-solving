class Solution {
public:
    bool valid(string s)
    {
        for(int i=0,j=s.size()-1;i<=j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                string temp = s;
                string s1= s.erase(i, 1);
                cout<<s1<<endl;
                s = temp;
                string s2 = s.erase(j, 1);
                cout<<s2<<endl;
                if(!valid(s1) && !valid(s2))
                {
                    return false;
                }
                else
                {
                    break;
                }
            }
        }
        return true;
    }
};