class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int mini = 1e9+7;
        int n = tops.size();
        for(int i=1;i<=6;i++)
        {
            int valid = 1;
            int cnt=0;
            //make all top by i
            for(int j=0;j<n;j++)
            {
                if(tops[j]!=i)
                {
                    if(bottoms[j]==i)
                    {
                        cnt++;
                    }
                    else
                    {
                        valid = 0;
                    }
                }
                
            }
            
            if(valid)
            {
                mini = min(mini, cnt);
            }
            
            cnt=0;
            valid = 1;
            
            for(int j=0;j<n;j++)
            {
                if(bottoms[j]!=i)
                {
                    if(tops[j]==i)
                    {
                        cnt++;
                    }
                    else
                    {
                        valid = 0;
                    }
                }
                
            }
            
            if(valid)
            {
                mini = min(mini, cnt);
            }
        }
        
        return mini==1e9+7?-1:mini;
    }
};