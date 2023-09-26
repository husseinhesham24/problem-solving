class Solution {
public:
    static bool cmp(string &a, string &b)
    {
        return a.size()<b.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int>h;
        int ans=0;
        for(auto w:words)
        {
            int maxi=0;
            for(int i=0;i<w.size();i++)
            {
                string temp = w;
                temp = temp.erase(i,1);
                maxi = max(maxi, h[temp]+1);
            }

            h[w] = maxi;
            ans = max(maxi, ans);
        }

        return ans;
    }
};