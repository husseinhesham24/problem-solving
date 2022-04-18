class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum=0;
        int n=0;
        vector<int>x;
        for(auto it:ops)
        {
            if(it=="C")
            {
                sum-=x[n-1];
                n--;
                x.pop_back();
            }
            else if(it=="+")
            {
                x.push_back(x[n-1]+x[n-2]);
                n++;
                sum+=x[n-1];
            }
            else if(it=="D")
            {
                x.push_back(x[n-1] * 2);
                n++;
                sum+=x[n-1];
            }
            else
            {
                x.push_back(stoi(it));
                n++;
                sum+=x[n-1];
            }
        }
        return sum;
    }
};