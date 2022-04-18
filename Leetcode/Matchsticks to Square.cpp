class Solution {
public:
    
    int sum=0;
    int n;
    bool check(int i, vector<int> &x, int g1, int g2, int g3, int g4)
    {
        if(i<0)
        {
            return ((g1==0) && (g2==0) && (g3==0) && (g4==0));
        }
        
        if((g1<0) || (g2<0) || (g3<0) || (g4<0))
        {
            return false;
        }
        
        
        return check(i-1, x, g1-x[i],g2,g3,g4) || check(i-1, x, g1,g2-x[i],g3,g4) || 
               check(i-1, x, g1,g2,g3-x[i],g4) || check(i-1, x, g1,g2,g3,g4-x[i]);
    }
    
    bool makesquare(vector<int>& x) {
        
        n=x.size();
        sum = accumulate(x.begin(), x.end(), sum);
        
        
        if(sum%4!=0 || n<4)
        {
            return false;
        }
        
        
        sum/=4;
    
        return check(n-1,x,sum,sum,sum,sum);
    }
};