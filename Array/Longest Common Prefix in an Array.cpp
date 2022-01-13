class Solution
{
  public:
    string longestCommonPrefix (string str[], int n)
    {
        sort(str,str+n);
        string s1=str[0];
        string s2=str[n-1];
        int i=0;
        int j=0;
        string ans="";
        while(i<s1.length()&&j<s2.length())
        {
            if(s1[i]==s2[j])
            {
                ans=ans+s1[i];
                i++;
                j++;
            }
            else
            {
                break;
            }
        }
        if(ans=="")
        {
            ans="-1";
        }
        return ans;
    }
};