/*Complexity :- N*sqrt(n)*/
class Solution
{
    public: 
    int prime(int N)
    {
        int flag=0;
        if(N==1)
        {
            return 0;
        }
        else if(N==2)
        {
            return 1;
        }
        else
        {
        for(int i=2;i<=sqrt(N);i++)
        {
            if(N%i==0&&N!=2)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        }   
    }
    long long int largestPrimeFactor(int N)
    {
        long long ans=INT_MIN;
        if(prime(N))
        {
            return N;
        }
        else
        {
            for(long long i=2;i<=N;i++)
            {
                if(N%i==0)
                {
                    if(prime(i))
                    {
                        ans=max(ans,i);
                    }
                }
            }
            return ans;
        }
    }
};

/*Complexity :- sqrt(n)*/
class Solution
{
public: 
    long long int largestPrimeFactor(int N)
    {
        int ans=1;
        int m=N;
        for(int i=2;i*i<=m;i++)
        {
            while(N%i==0)
            {
                  ans=i;
                  N=N/i;
            }
              
        }
        ans=max(ans,N); 
        return ans;
    }
};
