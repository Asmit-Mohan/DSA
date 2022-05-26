class Solution
{
public:
    void find(string s,string str,vector<string>&ans,set<string>&st)
    {
        if(s.size()==0)
        {
            str.pop_back();     /*Delete Last Space*/
            ans.push_back(str);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            string left=s.substr(0,i+1);
            if(st.count(left))
            {
                string right=s.substr(i+1);
                find(right,str+left+" ",ans,st);
            }
        }       
    }
    
    vector<string> wordBreak(string str, vector<string>& word) 
    {
        set<string>s(word.begin(),word.end());
        vector<string>ans;
        find(str,"",ans,s);
        return ans;
    }
};

/*
    Logic:- 
    Find left part and search in dict if found then add a space then search for remaining right part
    when right part size becomes zero that means this one combination is possible then add to ans vector
*/
