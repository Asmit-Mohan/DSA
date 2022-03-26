class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans=0;
        int i=1;
        
        while(1)
        {
            int quotient=n/pow(5,i);
            if(quotient==0)
            {
                break;
            }
            ans=ans+quotient;
            i++;
        }
        return count;
    }
};

/*Number of zero = number of power of 10 ie. number of power of 5*/
