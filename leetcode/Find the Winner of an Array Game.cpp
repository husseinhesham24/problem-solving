class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi=arr[0];
        int cnt=0;
        for(int i=1;i<arr.size();i++)
        {   
            if(maxi>arr[i])
            {
                cnt++;
                if(cnt==k)
                {
                    return maxi;
                }
            }
            else
            {
                cnt = 1;
                maxi = arr[i];
                if(cnt==k)
                {
                    return maxi;
                }
            }
        }

        return maxi;
    }
};