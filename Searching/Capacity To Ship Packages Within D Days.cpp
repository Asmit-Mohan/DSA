class Solution
{
  public:
  int canShip(int arr[],int n,int dayAvail,int boatCap)
    {
        int days=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum>boatCap)
            {
                days++;      /*we require more days*/
                sum=arr[i];  /*next element will start with this new added boat*/
            }
            if(days>dayAvail)
            {
               return 0;
            }
        }
        return 1;
    }
    
    int leastWeightCapacity(int arr[], int n, int days)
    {
        int l=*max_element(arr,arr+n);    /*Beacuse maximum element cannot be accomodated if boat size < maximum of array*/
        int r=0;
        for(int i=0;i<n;i++)
        {
            r=r+arr[i];        /*to ship all element in one trip require sum of all*/
        }
        int res=-1;
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(canShip(arr,n,days,mid))
            {
                res=mid;
                r=mid-1;     // To find more optimised solution
            }
            else
            {
                l=mid+1;
            }
        }
        return res;
    }
};
