/* Time :- O(N) Space :- O(1) */

class Solution
{
  public:
    int isGoodorBad(string S)
    {
        int vow=0;
        int cons=0;
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')
            {
                cons=0;
                vow++;
            }
            else if(S[i]=='?')
            {
                cons++;
                vow++;
            }
            else
            {
                cons++;
                vow=0;
            }
            if(cons>3||vow>5)
            {
                return 0;
            }
        }
        return 1;
    }
};
