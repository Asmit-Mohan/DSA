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
