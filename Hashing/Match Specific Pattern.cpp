bool solve(string txt,string pat)
{
    unordered_map<char,char>mp;
    if(txt.length()!=pat.length())
    {
        return 0;
    }
    else
    {
        for(int i=0;i<pat.length();i++)
        {
            if(mp.find(pat[i])==mp.end())
            {
                mp[pat[i]]=txt[i];
            }
            else
            {
                if(mp[pat[i]]!=txt[i])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<string> findMatchedWords(vector<string> arr,string s)
{
   vector<string>ans;
   for(int i=0;i<arr.size();i++)
   {
       if(solve(arr[i],s))
       {
          ans.push_back(arr[i]);   
       }
   }
   return ans;
}
