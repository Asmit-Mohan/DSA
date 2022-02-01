class Solution
{
    public:
    long long getNextEven(string s1)
    {
        long long num1,num2;
        string s2=s1;
        
        num1=stoll(s1);
        sort(s2.begin(),s2.end());
        reverse(s2.begin(),s2.end());
        num2=stoll(s2);
        
        while(num2>num1)
        {
           bool temp=next_permutation(s1.begin(),s1.end());
           if(temp==true)
           {
                num1=stoll(s1);
                if(num1%2==0)
                {
                    return num1;
                }
           }
        }
        return -1;
    }
};
