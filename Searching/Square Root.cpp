/* Time :- O(logn) Space :- O(1) */

class Solution
{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x==1)
        {
            return 1;
        }
        long long int low=0;
        long long int high=x/2;
        long long int ans;
        
        while(low<=high)
        {
            long long int mid=low+(high-low)/2;
            long long int temp=mid*mid;
            
            if(temp==x)
            {
                return mid;
            }
            else if(temp>x)
            {
                 high=mid-1;
            }
            else
            {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};
