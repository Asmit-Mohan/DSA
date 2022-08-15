/* Time :- O[log(N!)] Space :- (N) */

class Solution
{
    public:
    long long getNextEven(string s1)
    {
        string s2=s1;
        sort(s2.begin(),s2.end(),greater<int>());
        
        long long num1=stoll(s1);
        long long num2=stoll(s2);
        
        while(num2>num1)
        {
            bool val=next_permutation(s1.begin(),s1.end());
            if(val==true)
            {
               num1 = stoll(s1);
               if(num1%2==0)
               {
                   return num1;
               }
            }
        }
        return -1;
    }
};

/* Leetcode Next Greater Element 3 (Only Even Part is missing) */

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string s1=to_string(n);
        string s2=s1;
        sort(s2.begin(),s2.end(),greater<int>());
        
        long long num1=stoll(s1);
        long long num2=stoll(s2);
        long long range = 2147483647;
        
        while(num2>num1)
        {
            bool val=next_permutation(s1.begin(),s1.end());
            if(val==true)
            {
               num1 = stoll(s1);
               if(num1%2==0&&num1<=range)
               {
                    return num1;
               }
            }
        }
        return -1;    
    }
};
