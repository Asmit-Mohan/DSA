class Solution
{
public:
    string minWindow(string s, string t)
    {
         unordered_map<char,int>mp; 
         for (auto x : t)
         {
            mp[x]++;
         }
        
         int count = mp.size();
         int res = INT_MAX;
         int i =0;
         int j =0;
         string ans;
        
         while (j<s.size())
         {      
               if(mp.find(s[j])!= mp.end())
               {
                  mp[s[j]]--;
                  if(mp[s[j]]==0)
                  {
                     count--;
                  }

               }
               while(count==0)
               {
                      if(res>j-i+1)
                      {
                           res= min(res,j-i+1);
                           ans=s.substr(i,j-i+1);
                      }
                      if(mp.find(s[i])!=mp.end())
                      {
                          mp[s[i]]++;
                          if(mp[s[i]]==1)
                          {
                             count++;
                          }
                      }
                      i++;
                }
                j++;
          }
        return ans;
    }   
};
