class Solution {
public:
    string simplifyPath(string path) {
        
        if(path.back()!='/')
        {
            path+="/";
        }
        
        int n = path.size();
        string ans="/";
        vector<string>dictionary;
        string str="";
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
            {
                if(str==".." || str==".")
                {
                    if(dictionary.size() && str=="..")
                    {
                        dictionary.pop_back();
                    }
                }
                else if(str.size()>0)
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