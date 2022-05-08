/* Binomial Coffcient Approach */ /*Intution :- Nth Catalan number is equal to (2ncn)/(n+1) */

class Solution
{
public:
unsigned long int binomialCoefficient(int n,int i)  /* Calculation of 2ncn */
{
        unsigned long int ans = 1;
        if(i==0||i==n)
        {
            return 1;
        }
        if(i>n-i)
        {
            i=n-i;
        }
        for(int j=0;j<i;j++)
        {
            ans=ans*(n-j);
            ans=ans/(j+1);
        }
        return ans;
}

    int numTrees(int n) 
    {
        unsigned long int c = binomialCoefficient(2*n,n);
        return c/(n+1);
    }
};

/* DP Approach */

class Solution
{
    public:
    int numTrees(int n) 
    {
        long long int dp[n+1]={0};
        long long int mod=pow(10,9)+7;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++)
        {
            for(int j=0;j<i;j++)
            { 
                long long res=((dp[j]*dp[i-j-1])%mod);
                dp[i]=(dp[i]+res)%mod;
            }
        }
        return dp[n];
    }
};
