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
            swap(arr[idx],arr[i]);
        }
    }
     
    void selectionSort(int arr[], int n)
    {
       select(arr,n);
    }
};
