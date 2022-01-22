class Solution
{
  public:
    int atoi(string str)
    {
        int ans=0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                return -1;
            }
        }
        if(str.length()==1)
        {
            int num=str[0]-'0';
            return num;
        }
        if(str[0]=='-')
        {
             int n=str.length()-2;
             for(int i=1;i<str.length();i++)
             {
                ans=ans+((str[i]-'0')*(pow(10,n)));
                n--;
             }
             ans=ans*-1;
        }
        else
        {
            int n=str.length()-1;
            for(int i=0;i<str.length();i++)
            {
                ans=ans+((str[i]-'0')*(pow(10,n)));
                n--;
            }
        }
        return ans;
    }
};
