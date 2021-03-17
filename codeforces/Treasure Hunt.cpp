#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mk make_pair

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    string x, y, z;
    cin >> x >> y >> z;
    ll sz = x.size();
    unordered_map<char, ll>h1,h2,h3;

    
    ll maxi_x = 0;
    ll maxi_y = 0;
    ll maxi_z = 0;

    //get max occur character in each string
    for(int i=0;i<sz;i++)
    {
        maxi_x = max(maxi_x, ++h1[x[i]]);
        maxi_y = max(maxi_y, ++h2[y[i]]);
        maxi_z = max(maxi_z, ++h3[z[i]]);
    }

    //corner case
    if(n==1 && maxi_x==sz)
    {
        x.pop_back();
    }

    if(n==1 && maxi_y==sz)
    {
        y.pop_back();
    }

    if(n==1 && maxi_z==sz)
    {
        z.pop_back();
    }


    //calculate each max after n turns
    maxi_x = min((ll)x.size(), maxi_x+n);
    maxi_y = min((ll)y.size(), maxi_y+n);
    maxi_z = min((ll)z.size(), maxi_z+n);


    //get winner
    if(maxi_x>maxi_y && maxi_x>maxi_z)
    {
        cout<<"Kuro"<<endl;
    }
    else if(maxi_y>maxi_x && maxi_y>maxi_z)
    {
        cout<<"Shiro"<<endl;
    }
    else if(maxi_z>maxi_x && maxi_z>maxi_y)
    {
        cout<<"Katie"<<endl;
    }
    else
    {
        cout<<"Draw"<<endl;
    }
    

    return 0;
}