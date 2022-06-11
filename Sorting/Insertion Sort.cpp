class Solution
{
    public:
    void insert(int arr[], int i)
    {
        int j=i-1;
        while(j>=0&&arr[j]>arr[i]) 
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=arr[i];
    }
  
    public:
    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++)
        {
           insert(arr,i);  
        }
    }
};
