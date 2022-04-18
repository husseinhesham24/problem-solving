class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i=0,j=0;
        for(;i<n && j<m;i++)
        {
            if(t[i]==s[j])
            {
                j++;
            }
        }
        return j==m;
    }
};