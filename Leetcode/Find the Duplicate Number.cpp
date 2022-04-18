class Solution {
public:
    int findDuplicate(vector<int>& x) {
        sort(x.begin(), x.end());
        long long ans=0;
        for(int i=0;i<x.size()-1;i++)
        {
            if(x[i]==x[i+1])
            {
                ans = x[i];
                break;
            }
        }
        return ans;
    }
};