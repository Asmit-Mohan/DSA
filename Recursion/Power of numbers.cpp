/* Time :- O(logn) Space :- O(logn) --> Divide and Conquer Approach */

class Solution
{
    public:
    long long power(int N,int R)
    {
       if(R==0)
       {
          return 1;
       }
       if(R==1)
       {
           return N;
       }
       
       long long temp = power(N,R/2)%mod;
       temp=(temp*temp)%mod;
       if(R%2==0)
       {
           return (temp)%mod;
       }
       else
       {
           return (N*temp)%mod;
       }
    }
};
