class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", t1 = "";

        for(auto it:s)
        {
            if(it=='#')
            {
                if(!s1.empty())
                {
                    s1.pop_back();
                }
            }
            else
            {
                s1+=it;
            }
        }

        for(auto it:t)
        {
            if(it=='#')
            {
                if(!t1.empty())
                {
                    t1.pop_back();
                }    
            }
            else
            {
                t1+=it;
            }
        }

        //cout<<s1<<"     "<<t1<<endl;
        return s1==t1;
    }
};