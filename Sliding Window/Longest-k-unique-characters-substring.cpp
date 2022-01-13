class Solution
{
  public:
    int longestKSubstr(string s, int k)
    {
       int i=0;
       int j=0;
       int n=s.length();
       unordered_map<char,int>mp;
       int ans=-1;
       
       while(j<n)
       {
          mp[s[j]]++;
          if(mp.size()<k)
          {
              j++;
          }
          
          if(mp.size()==k)
          {
             ans=max(ans,j-i+1);
             j++;
          }
         
           if(mp.size()>k)
           {
               while(mp.size()>k)
               {
                   mp[s[i]]--;
                   if(mp[s[i]]==0)
                   {
                       mp.erase(s[i]);
                   }
                   i++;
               }
               j++;
           }
       }
       return ans;
    }
};