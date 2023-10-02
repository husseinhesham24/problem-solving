class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        for(auto c:s)
        {
            if(isdigit(c))
            {
                len *= (c-'0');
            }
            else
            {
                len++;
            }   
        }


        for(int i=s.size()-1;i>=0;i--)
        {
            if(isdigit(s[i]))
            {
                len/=(s[i]-'0');
                k = k%len;
            }
            else
            {
                if(k==0 || len==k)
                {
                    return string("")+s[i];
                }
                len--;
            }
        }

        return "";
    }
};