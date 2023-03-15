class Solution {
public:

   static bool cmp(pair<char, pair<int,int>>&a, pair<char, pair<int,int>>&b)
    {
        if(a.second.first==b.second.first)
        {
            return a.second.second<b.second.second;
        }
        return a.second.first<b.second.first;
    }

    string convert(string s, int numRows) {

        if(numRows==1)
        {
            return s;
        }

        int r = numRows, n = s.size();
        vector<pair<char, pair<int,int>>>x(n);
        int j=0;
        int cnt=0;
        x[cnt].first = s[cnt];
        x[cnt].second.first = 0;
        x[cnt].second.second = 0;
        cnt++;
        
        while(cnt<n)
        {
            for(int i=1;i<r && cnt<n;i++)
            {
                x[cnt].first = s[cnt];
                x[cnt].second.first = i;
                x[cnt].second.second = j;
                cnt++;
            }

            for(int i=r-2;i>=0 && cnt<n;i--)
            {
                j++;
                x[cnt].first = s[cnt];
                x[cnt].second.first = i;
                x[cnt].second.second = j;
                cnt++;
            }
            
        }

        //debugging
        // for(int i=0;i<n;i++)
        // {
        //     cout<<x[i].first<<" "<<x[i].second.first<<" "<<x[i].second.second<<endl;
        // }

        
        sort(x.begin(), x.end(), cmp);
        
    
        string ans = "";
        for(int i=0;i<n;i++)
        {
            ans+=x[i].first;
        }

        return ans;
    }
};