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
