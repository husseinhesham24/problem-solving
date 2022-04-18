#include <bits/stdc++.h>

class Solution {
public:
    
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

long long ans=0;

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    sort(boxTypes.begin(), boxTypes.end(), cmp);
    for(int i=0;i<boxTypes.size();i++)
    {
        long long a=0,b=0;
        for(int j=0;j<2;j++)
        {
            a = (j==0?boxTypes[i][j]:a);
            b = (j==1?boxTypes[i][j]:b);
        }
    
        cout<<a<<" "<<b<<endl;
        if(truckSize>=a)
        {
            ans+=(a*b);
            truckSize-=a;
        }
        else
        {
            ans+=((truckSize%a)*b);
            return ans;
        }
    }

    return ans;
}
};