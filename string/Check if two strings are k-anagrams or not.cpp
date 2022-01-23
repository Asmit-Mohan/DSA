class Solution
{
  public:
    bool areKAnagrams(string str1, string str2, int k)
    {
        if(str1.length()!=str2.length())
        {
            return 0;
        }
        int count=0;
        int hash[26]={0};
        for(int i=0;i<str1.length();i++)
        {
            hash[str1[i]-'a']++;
            hash[str2[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
           count=count+abs(hash[i]);
        }
        if(k>=count/2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
