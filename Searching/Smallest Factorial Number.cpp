class Solution
{
    public:
    int solve(int n)
    {
        int i=1;
        int quotient=1;
        int ans=0;
        
        while(quotient>0)
        {
            quotient = n/pow(5,i);
            ans = ans + quotient;
            i++;
        }
        return ans; 
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
            if(temp>=n)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};
