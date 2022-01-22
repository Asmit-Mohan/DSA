/*Approach 1*/

bool solve(int idx,string s,string x)
{
    for(int i=idx;i<idx+x.length();i++)
    {
        if(s[i]!=x[i-idx])
        {
            return 0;
        }
    }
    return 1;
}
int strstr(string s, string x)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==x[0])
        {
            if(solve(i,s,x))
            {
                return i;
            }
        }
    }
    return -1;
}

/*Approach 2*/

int strstr(string s, string x)
{
    if(s.length()==0||x.length()==0)
    {
         return -1;
    }
    else
    {
         int i=0;
         int j=0;
         while(i<s.length())
         {
             while(i<s.length()&&j<x.length()&&s[i]==x[j])
             {
                 i++;
                 j++;
             }
             if(j==x.length())
             {
                 return i-x.length();
             }
             else
             {
                 j=0;
             }
             i++;
         }
         return -1;
    }
}
