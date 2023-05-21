class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int>h;
        for(int i=0;i<words.size();i++)
        {
            h[words[i]]++;
        }

        vector<pair<string,int>>x(h.begin(), h.end());
        vector<string>ans;
        sort(x.begin(), x.end(), 
            [&k](pair<string, int>&a, pair<string, int>&b)
            {
                if(a.second==b.second)
                {
                    return a.first<b.first;
                }
                return a.second>b.second;
            }
        );
        for(int i=0;i<k;i++)
        {
            ans.push_back(x[i].first);
        }
        return ans;
    }
};