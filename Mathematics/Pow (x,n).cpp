/* Approach 1 :- Iterative */

class Solution
{
public:
    double myPow(double x, int n)
    {
       if(n==0)
       {
           return 1;
       }
       if(n==1)
       {
           return x;
       }
       if(n==-1)
       {
           return (double)1/x;
       }
       if(n<0)
       {
           n=abs(n);
           x=1/x;
       }
       double res=1.0;
       long long N=n;
       
       long long i=1;
       while(i<=N)
       {
           res*=x;
           if(i*2<N)   /* Optimisation step ie. if double the current power is less than the required power then double the result */
           {
               i=(i*2)+1;
               res*=res;
           }
           else
           {
               i++;
           }
       }
       return res; 
    }
};

/* Approach 2 :- Recursive */

class Solution
{
public:
    double myPow(double x, int n)
    {
        if(x==1||n==0)
        {
            return (double)1;
        }
        else if(n==1)
        {
            return x;
        }
        else if(n==-2147483648)
        {
            return (double)0;
        }
        else if(x==-1&&n%2==0)
        {
            return (double)1;
        }    
        else if(x==-1&&n%2==1)
        {
            return (double)-1;
        }
        else if(n<0)
        {
            n*=-1;
            x=1.00/x;
        }
        return x*pow(x,n-1);
    }
};
