#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mk make_pair

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string x;
    cin >> x;

    ll zero = count(x.begin(), x.end(), '0');
    ll one = count(x.begin(), x.end(), '1');
    ll two = count(x.begin(), x.end(), '2');

    //check the occurance of each character
    ll sum = (zero > 0) + (one > 0) + (two > 0);

    if (sum == 1) //there is one character
    {
        cout << x << endl;
    }
    else if (sum == 2) //there are two characters 
    {
        if (one && (two || zero)) //check if it is 1s and 0s or 1s and 2s
        {
            sort(x.begin(), x.end());
            cout << x << endl;
        }
        else
        {
            cout << x << endl; // 0s and 2s
        }
    }
    else
    {   
        //sorting 0s and 1s befor the first occurance of 2 
        string temp = "";
        for (int i = 0; x[i]; i++)
        {
            if (x[i] == '2')
            {
                break;
            }

            temp += x[i];

            zero -= (x[i] == '0');

            one -= (x[i] == '1');
        }

        sort(temp.begin(), temp.end());
        cout << temp;

        //drop all remaining 1s 
        while (one--)
        {
            cout << '1';
        }
        
        //take all positions of 2s 
        vector<ll> pos;
        for (int i = 0; x[i]; i++)
        {
            if (x[i] == '2')
            {
                pos.push_back(i);
            }
        }

        cout << '2';

        for (int i = 0; i < (signed)pos.size() - 1; i++)
        {

            //count num of 0s between 2....2
            ll cnt_0 = count(x.begin() + pos[i], x.begin() + pos[i + 1], '0');

            zero -= cnt_0;

            while (cnt_0--)
            {
                cout << '0';
            }
            cout << '2';
        }

        // drop all 0s
        while (zero--)
        {
            cout << '0';
        }
        cout << endl;
    }

    return 0;
}
