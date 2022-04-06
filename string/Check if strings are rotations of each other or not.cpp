/*Approach 1*/

class Solution
{
    public:
    bool areRotations(string s1,string s2)
    {
        if(s1.size()!=s2.size())
        {
           return 0;
        }
        if(s1.size()==s2.size() && s1==s2)
        {
           return 1;
        }
        
        queue<char>q1,q2;
        
        for(int i=0;i<s1.length();i++)
        {
            q1.push(s1[i]);
        }
        for(int i=0;i<s2.length();i++)
        {
            q2.push(s2[i]);
        }
        
        int size=s1.length();
        
        while(size--)
        {
            char temp=q1.front();
            q1.pop();
            q1.push(temp);
            if(q1==q2)
            {
                return 1;
            }
        }
        return 0;
    }
};

/*Approach 2*/

class Solution
{
    public:
    bool areRotations(string s1,string s2)
    {
       if(s1.size()!=s2.size())
       {
           return 0;
       }
       if(s1.size()==s2.size() && s1==s2)
       {
           return 1;
       }
       string res=s1+s1;
       int n=res.size();
       int m=s2.size();
       for(int i=0;i<n-m;i++)
       {
            if(res.substr(i,m)==s2)
              {
                  return 1;
              }
        }
        return 0;
    }
};
