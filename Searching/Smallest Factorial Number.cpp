class Solution
{
    public:
    int solve(int check)
    {
        int count=0;
        int i=1;
        
        while(1)
        {
            int quotient=check/pow(5,i);
            if(quotient==0)
            {
                break;
            }
            count=count+quotient;
            i++;
        }
        return count;
    }
    int findNum(int n)
    {
        int low=1;
        int high=5*n;
        int ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int temp=solve(mid);
            if(temp==n)
            {
                ans=mid;
                high=mid-1;
            }
            else if(temp<n)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
};
