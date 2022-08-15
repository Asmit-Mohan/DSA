/* Time :- O(N) Space :- O(N) */

/* Approach 1 */

class Solution
{
    public:
    bool isRotated(string str1, string str2)
    {
        if(str1.length()!=str2.length())
        {
            return 0;
        }
        string op;
        int flag1=1;
        int flag2=1;
        for(int i=2;i<str1.length();i++)
        {
            op+=str1[i];
        }
        op+=str1[0];
        op+=str1[1];
        for(int i=0;i<str1.length();i++)
        {
            if(op[i]!=str2[i])
            {
                flag1=0;
            }
        }
        
        op.clear();
        
        op+=str1[str1.length()-2];
        op+=str1[str1.length()-1];
        for(int i=0;i<str1.length()-1;i++)
        {
            op+=str1[i];
        }
        for(int i=0;i<str1.length();i++)
        {
            if(op[i]!=str2[i])
            {
                flag2=0;
            }
        }
        
        if(flag1==0&&flag2==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

/* Approach 2 */

class Solution
{
    public:
    bool isRotated(string str1, string str2)
    {
       int n=str1.length();
       int m=str2.length();
       if(m!=n)
       {
           return 0;
       }

       string s=str1.substr(2,m-2)+str1.substr(0,2);
       
       if(s==str2)
       {
           return 1;
       }
       
       s=str1.substr(m-2,2)+str1.substr(0,m-2);
       
       if(s==str2)
       {
           return 1;
       }
       
       return 0;
    }
};
