/* Approch 1 */

class Solution
{
public:
    bool isprime(int n)
    {
        if (n<2)
        {
            return false;
        }
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    int primeSetBits(int L, int R)
    {
        int c=0;
        for(int i=L;i<=R;i++)
        {
            int p=__builtin_popcount(i);
            if(isprime(p))
            {
                c++; 
            }
        }
        return c;
    }
};


/* Approach 2 */

class Solution
{
public:
    bool isprime(int n)
    {
        if (n<2)
        {
            return false;
        }
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    int primeSetBits(int L, int R)
    {
        int c=0;
        int dp[R+1];
        
        dp[0]=0;
        for(int i=1;i<=R;i++)
        {
            dp[i]=dp[i/2]+i%2;
        }
        
        for(int i=L;i<=R;i++)
        {
            if(isprime(dp[i]))
            {
                c++; 
            }
        }
        return c;
    }
};
