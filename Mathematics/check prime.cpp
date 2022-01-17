class Solution
{
public:
    int isPrime(int n)
    {
        if(n==1)
        {
            return 0;
        }
        int temp=sqrt(n);
        for(int i=2;i<=temp;i++)
        {
            if(n%i==0)
            {
                return 0;
            }
        }
        return 1;
    }
};
