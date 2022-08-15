/* Time :- O(N) Space :- O(N) */

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
       int preFre=INT_MIN;
       int postFre=INT_MIN;
       
       unordered_map<string,int>mp;
       for(int i=0;i<n;i++)
       {
           mp[arr[i]]++;
       }
       
       for(auto x : mp)
       {
           if(x.second>postFre)
           {
               preFre=postFre;
               postFre=x.second;
           }
           else if(x.second>preFre)
           {
               preFre=x.second;
           }
       }
       
       for(auto x : mp)
       {
           if(x.second==preFre)
           {
               return x.first;
           }
       }
       return "";
    }
};
