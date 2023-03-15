class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>h;
        for(int i=0;i<order.size();i++)
        {
            h[order[i]] = i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            string s1 = words[i], s2 = words[i+1];
            bool flag=true;
            for(int j=0;j<min(s1.length(), s2.length());j++)
            {
                if(h[s1[j]]<h[s2[j]])
                {
                    flag = false;
                    break;
                }
                else if(h[s1[j]]>h[s2[j]])
                {
                    cout<<s1[j]<<" : "<<h[s1[j]]<<"  "<<s2[j]<<" : "<<h[s2[j]]<<endl;
                    return false;
                }
            }

            if(flag && s1.length()>s2.length())
            {
                return false;
            }
        }

        return true;
    }
};