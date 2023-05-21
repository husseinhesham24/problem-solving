class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string ans="";
        for(int i=0;i<max(n,m);i++)
        {
            if(i<n)
            {
                ans+=word1[i];
            }
            if(i<m)
            {
                ans+=word2[i];
            }
        }

        return ans;
    }
};