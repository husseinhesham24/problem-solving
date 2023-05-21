class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0, n = arr.size();
        unordered_map<int,int>h;
        for(int i=0;i<n;i++)
        {
            h[arr[i]]++;
        }

        for(int i=1;k>0;i++)
        {
            if(h[i]==0)
            {
                k--;
                if(k==0)
                {
                    return i;
                }
            }
        }

        return 0;
    }
};