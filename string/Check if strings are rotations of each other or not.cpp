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
