class Solution
{
public:
      int isPossible (string S)
      {
          int hash[26]={0};
          int count=0;
          for(int i=0;i<S.length();i++)
          {
              hash[S[i]-'a']++;
          }
          for(int i=0;i<26;i++)
          {
              if(hash[i]%2!=0)
              {
                  count++;
              }
          }
          if(count>1)
          {
              return 0;
          }
          else
          {
              return 1;
          }
      }
};
