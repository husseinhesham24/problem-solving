class Solution {
public:
    #define ll long long
    int titleToNumber(string columnTitle) {
        
        string x = columnTitle;
        int n = x.size();
        int n1 = 0;
        ll ans=0;
        for(int i=n-1;i>=0;i--)
        {   
            ans += pow(26, n1)*(x[i]-65+1);
            n1++;
        }    
        return ans;
    }
};