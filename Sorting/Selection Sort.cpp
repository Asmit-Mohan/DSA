/* Time :- O(N*N) Space :- O(1) */

class Solution
{
    public:
    int select(int arr[], int n)
    {
        for(int i=0;i<n-1;i++)
        {
            int idx=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[idx]>arr[j])
                {
                    idx=j;
                }
            }
            if(idx!=i)
            {
                swap(arr[idx],arr[i]);
            }
        }
    }
     
    void selectionSort(int arr[], int n)
    {
       select(arr,n);
    }
};

/* Key points :- The default implementation is not stable. However it can be made stable. It is in-place algo since it does not require extra space */
