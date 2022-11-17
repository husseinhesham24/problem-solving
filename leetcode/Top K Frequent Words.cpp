class Solution {
public:
    
    static bool cmp(pair<int, string>&a, pair<int, string>&b)
    {
        if(a.first!=b.first)
        {
            return a.first>b.first;   
        }
        
        return a.second<b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>h;
        int n = words.size();
        vector<pair<int,string>>x;
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            h[words[i]]++;
        }
        for(auto it:h)
        {
            x.push_back({it.second,it.first});
        }
        sort(x.begin(),x.end(),cmp);
        for(int i=0;i<k;i++)
        {
            //cout<<it.first<<" "<<it.second<<endl;
            ans.push_back(x[i].second);
        }
        return ans;
    }
};