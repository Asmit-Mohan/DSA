/* Time :- O(N) Space :- O(Number of unique charecter in str) */

class Solution
{
    public:
    int findSubString(string str)
    {
       unordered_map<char,int>mp;  
       for(auto x : str)
       {
           mp[x]++;
       }
       
       int i=0;
       int j=0;
       int unique=mp.size();
       int ans=INT_MAX;
       mp.clear();
       
       while(j<str.length())
       {
           mp[str[j]]++;
           
           if(mp.size()==unique)
           {
               while(i<=j&&mp.size()==unique)
               {
                   if(mp[str[i]]==1)
                   {
                       int window=j-i+1;
                       ans=min(ans,window);
                       break;
                   }
                   else
                   {
                       mp[str[i]]--;
                       i++;
                   }
               }
               j++;
           }
           else
           {
               j++;
           }
       }
       return ans;
    }
};
