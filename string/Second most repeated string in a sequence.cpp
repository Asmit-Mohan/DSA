class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
       string preStr="";
       string postStr="";
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
               preStr=postStr;
               preFre=postFre;
               postStr=x.first;
               postFre=x.second;
           }
           else if(x.second>preFre)
           {
               preFre=x.second;
               preStr=x.first;
           }
       }
       return preStr;
    }
};
