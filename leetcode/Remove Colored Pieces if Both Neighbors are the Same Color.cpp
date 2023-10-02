class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0, bob=0;
        int cnt=1, n = colors.size();
        colors += '@';
        for(int i=1;i<=n;i++)
        {
            if(colors[i]!=colors[i-1])
            {
                if(cnt>2)
                {
                    if(colors[i-1]=='A')
                    {
                        alice+=(cnt-2);
                    }
                    else
                    {
                        bob+=(cnt-2);
                    }
                }
                cnt=1;
            }
            else
            {
                cnt++;
            }
        }

        cout<<alice<<" "<<bob<<endl;
        return (alice>bob);
    }
};