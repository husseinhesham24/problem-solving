class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string ans="/";
        int i=n-1;
        int j=0;
        
        if(path.back()!='/')
        {
            path+="/";
            n++;
        }
        
        vector<string>dictionary;
        string str="";
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
            {
                if(str=="..")
                {
                    if(dictionary.size()>0)
                    {
                        dictionary.pop_back();
                    }
                }
                else if(str.size()>=1 && str!=".")
                {
                    dictionary.push_back(str);
                }
        
                str = "";
            }
            else
            {
                str+=path[i];
            }
        }
        
        for(int i=0;i<dictionary.size();i++)
        {
            ans+= dictionary[i]+"/";
        }
        
        if(ans.size()>1)
        {
            ans.pop_back();
        }
        return ans;
            
    }
};