/* Time :- O(Nlogn) Space :- O(1) */

class Solution 
{
    public:
    bool solve(int page,int arr[],int n,int student)
    {
        int stAvail=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum>page)
            {
                stAvail++;
                sum=arr[i];
            }
            if(stAvail>student)     /* ie. if student required is more than current available ,as per current alloction then false */
            {
                return 0;
            }
        }
        return 1;
    }
    int findPages(int arr[], int n, int student) 
    {
        if(student>n)
        {
            return -1;
        }
        int sum=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
        }
        int low=*max_element(arr,arr+n);
        int high=sum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(solve(mid,arr,n,student))
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
