class Solution
{
    public:
    string findSubString(string str)
    {
           int i=0;
           int j=0;
           int n=str.size();
           set<char>s;
           for(int i=0;i<str.length();i++)
           {
               s.insert(str[i]);
           }
           int unique=s.size();
           
           int k=0;
           unordered_map<char,int>mp;
           int window=INT_MAX;
           
           while(j<n)
           {
               mp[str[j]]++;
               if(mp.size()==unique)
               {
                   while(k<=j&&mp.size()==unique)
                   {
                       int temp=mp[str[k]]-1;
                       if(temp==0)
                       {
                           if(window>(j-k+1))
                           {
                               window=j-k+1;
                           }
                           break;
                       }
                       else
                       {
                           mp[str[k]]--;
                           k++;
                       }
                   }
                   j++;
               }
               else
               {
                   j++;
               }
           }
           string ans=str.substr(k,window);
           return ans;
    }
};
