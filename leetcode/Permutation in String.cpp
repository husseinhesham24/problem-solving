class Solution {
public:

    bool test(string &temp, int &unique, unordered_map<char,int>&h, int &m, unordered_map<char,int>&vis)
    {
        unordered_set<char>s;
        unordered_map<char,int>h1;
        int sum=0;
        for(auto it:temp)
        {
            if(vis[it])
            {
                h1[it]++;
                if(!s.count(it))
                {
                    sum+=h[it];
                    s.insert(it);
                }
            }
            else
            {
                return false;
            }
        }
        //cout<<s.size()<<" "<<unique<<" "<<sum<<" "<<m<<endl;
        if(s.size()==unique)
        {
            for(auto it:s)
            {
                if(h[it]!=h1[it])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }       

    

    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
        {
            return false;
        }
        else if(s1==s2)
        {
            return true;
        }

        
        s2+='#';
        int m = s1.length();
        int n = s2.length();
        unordered_map<char,int>h, vis;
        unordered_set<char>s;

        for(int i=0;i<m;i++)
        {
            h[s1[i]]++;
            vis[s1[i]] = 1;
            s.insert(s1[i]);
        }

        int unique=s.size();
        s.clear();        

        
        
        for(int i=0;i<n-m;i++)
        {
            string temp = s2.substr(i, m);
            //cout<<temp<<endl;
            if(test(temp, unique, h, m, vis))
            {
                return true;
            }
        }

        return false;
    }
};