/* Time :- O(N) Space :- O(N) */

class Solution
{
  public:
    string reverseWords (string str)
    {
        string ans="";
        string temp="";
        for(char it : str)
        {
            if(it=='.')
            {
                ans=ans+temp+".";
                temp="";
            }
            else
            {
                temp=it+temp;
            }
        }
        ans=ans+temp;
        return ans;
    }
};
