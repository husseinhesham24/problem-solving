class Solution {
public:
    
    string build(string x, int j, int n)
    {
        if(j==n)
        {
            return x;
        }
        
        int cnt=1;
        char last = x[0];
        string temp = "";
        for(int i=1;i<x.size();i++)
        {
            if(x[i]==last)
            {
                cnt++;
                continue;
            }
            
            temp+=to_string(cnt)+last;
            last = x[i];
            cnt = 1;
        }
        
        temp+=to_string(cnt)+last;
        return build(temp, j+1, n);
    }
    
    string countAndSay(int n) {
        return build("1", 1, n);
    }
};