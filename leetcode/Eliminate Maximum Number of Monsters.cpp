class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double>arr_time(n);
        for(int i=0;i<n;i++)
        {
            arr_time[i] = (double)dist[i]/speed[i];
        }

        sort(arr_time.begin(), arr_time.end());

        for(int i=0;i<n;i++)
        {
            if(arr_time[i]<=i)
            {
                return i;
            }
        }

        return n;
    }
};