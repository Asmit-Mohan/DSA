/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        long long int sum = 0;
        sort(arr,arr+n);
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0&&k>0)
            {
                k--;
                arr[i] = arr[i]*(-1);
            }
            sum=sum+arr[i];
        }
        
        if(k%2==1)
        {
            return sum - 2*(*min_element(arr,arr+n));
        }
        else
        {
            return sum;    
        }
    }
};
