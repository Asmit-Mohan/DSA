class Solution
{
public:	
int countTriplet(int arr[], int n)
{
        sort(arr,arr+n);
        int count=0;
        for(int i=0;i<n;i++)
        {
            int l=0;
            int r=n-1;
            while(l<r)
            {
                if(arr[l]+arr[r]==arr[i])
                {
                    count++;
                    l++;
                    r--;
                }
                else if(arr[l]+arr[r]<arr[i])
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return count;
}
};
