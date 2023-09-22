class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        if(n>m)
        {
            return false;
        }

        int j=0;
        for(int i=0;i<m;i++)
        {   
            if(s[j]==t[i])
            {
                j++;
            }
        }

        return j==n;
    }
};