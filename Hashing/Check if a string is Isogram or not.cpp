class Solution
{
    public:
    bool isIsogram(string s)
    {
    int flag=0;
    vector<int> hash(26,0);
    for(int i=0;i<s.length();i++)
    {
        hash[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
      {
          if(hash[i]==0 || hash[i]==1)
          {
              
          }
         else
          {
             flag=1;    
          }
      }
      if(flag==0)
      {
          return 1;
      }
      else
      {
          return 0;
      }
    }
};
