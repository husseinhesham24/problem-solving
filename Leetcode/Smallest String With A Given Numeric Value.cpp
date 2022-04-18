class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for(int i=0;i<n;i++)
        {
            ans+='a';
            k--;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(k>=26)
            {
                ans[i] = 'z';
                k-=25;
            }
            else
            {
                ans[i] = 'a'+k;
                //cout<<ans[i]<<" "<<k<<endl;
                break;
            }
        }
        return ans;
    }
};