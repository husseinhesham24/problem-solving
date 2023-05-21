class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(); 
        int m = needle.size();
        if(n<m)
        {
            return -1;
        }

        for(int i=0;i<=n-m;i++)
        {
            string temp=haystack.substr(i,m);
            if(temp==needle)
            {
                return i;
            }
        }

        return -1;
    }
};