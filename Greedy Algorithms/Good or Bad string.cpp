class Solution
{
  public:
    int isGoodorBad(string S)
    {
        int vow=0;
        int cons=0;
        int flag=1;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')
            {
                cons=0;
                vow++;
                if(vow>5)
                {
                    flag=0;
                    break;
                }
            }
            else if(S[i]=='?')
            {
                cons++;
                vow++;
                if(vow>5||cons>3)
                {
                    flag=0;
                    break;
                }
            }
            else
            {
                cons++;
                vow=0;
                if(cons>3)
                {
                    flag=0;
                    break;
                }
            }
        }
        return flag;
    }
};
