class Solution {
public:
    #define ll long long 
    const ll MOD = 1e9+7;
    int countOrders(int n) {
        ll res1 = 1, res2=1;
        for(int i=2;i<=n;i++)
        {
            res1 = (res1*i)%MOD;
        }
        
        for(int i=3;i<(2*n);i+=2)
        {
            res2 = (res2*i)%MOD;
        }
        
        return (res1*res2)%MOD;
    }
};